МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе №6 <br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы ПИ-192(2)<br/>
Лунгула Кирилла Александровича 
направления подготовки 09.03.04 "Программная инженерия"
<br/>
​
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)<br/></td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019
<br/><br/>

**Цель:**
Закрепить навыки разработки многофайловыx приложений;изучить способы работы с API web-сервиса; изучить процесс сериализации/десериализации данных.

**Ход работы:**
1. Разработка сервера на С++.
2. Работа с сервисом openweathermap.org.
3. Разработка клиента для получения информации от openweathermap.org.
4. Работа с JSON.
5. Заполнение шаблона виджета.
6. Сборка итогового проекта.
Cкриншот <br>

**Начало работы**
1. API ключ:"6fcd3f8e7b8b18fe6ab1aa2793fd272d".
2. Код:
```cpp
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
using namespace httplib;
using namespace nlohmann;

std::string GetWeather()
{
    // IMPORTANT: 1st parameter must be a hostname or an IP adress string.
    std::ifstream html;
    std::string S_html;
    html.open("lab6.html");
    if (html.is_open()) {
        getline(html, S_html, '\0');
        html.close();
    }
    else {
        std::cout << "WTF!!!";
    }

    httplib::Client cli("api.openweathermap.org", 80);

    auto res = cli.Get("/data/2.5/forecast?id=693805&appid=6fcd3f8e7b8b18fe6ab1aa2793fd272d&units=metric");

    json j = json::parse(res->body);
   // if (res && res->status == 200) {
       // std::cout << j.dump(4) << std::endl;
   // }
    std::string s_json = j.dump(4);
    int k = s_json.find("\"name\"");
    k += 7;
    int day = 0;
    while (true) {
        std::string s_name = "";
        if (s_json[k] == ':' || s_json[k] == ' ') {
            k++;
            continue;
        }
        else if (s_json[k] == '\"') {
            k++;
            while (s_json[k] != '\"')
            {
                s_name += s_json[k];
                k++;
            }
            int c = S_html.find("{city.name}");
            S_html.erase(c, 11);
            S_html.insert(c, s_name);
            break;
        }
    }
    //std::cout << std::endl;
    k = s_json.find("\"dt_txt\"");
    k += 9;
    std::string s_oldData = "no";

    while (true) {
        day++;

        while (true) {
            std::string s_newData = "";
            if (s_json[k] == ':' || s_json[k] == ' ') {
                k++;
                continue;
            }
            else if (s_json[k] == '\"') {
                k++;
                while (s_json[k] != ' ')
                {

                    s_newData += s_json[k];

                    k++;
                }

                if (s_oldData == "no") {
                   // std::cout << s_newData << std::endl;
                    s_oldData = s_newData;
                }
                else if (s_oldData == s_newData) {
                    k = s_json.find("\"dt_txt\"", k);
                   // if (k == -1 || day == 5) {
                     //   break;
                   // }
                    k += 9;
                    continue;
                }
                else if (s_oldData != s_newData) {
                  //  std::cout << s_newData << std::endl;
                    s_oldData = s_newData;
                }
                break;
            }
        }
        int c = S_html.find("{list.dt}");
        S_html.erase(c, 9);
        S_html.insert(c, s_oldData);
        k = s_json.find("\"temp\"", k);
        k += 6;
        std::string s_temp = "";
        while (true) {
            
            if (s_json[k] == ':' || s_json[k] == ' ') {
                k++;
                continue;
            }
            else {
               
                while (s_json[k] != ',')
                {
                    s_temp += s_json[k];
                    k++;
                }
                break;
            }
        }
        int a = S_html.find("{list.main.temp}");
        //std::cout << s_temp << std::endl;
        S_html.erase(a, 16);
        if (s_temp[0] != '-') {
            S_html.insert(a,'+'+s_temp);
        }
        else {
            S_html.insert(a, s_temp);
        }
        k = s_json.find("\"icon\"", k);
        k += 8;
        std::string s_icon = "";
        while (true) {
            if (s_json[k] == ':' || s_json[k] == ' ') {
                k++;
                continue;
            }
            else if (s_json[k] == '\"') {
                k++;
                while (s_json[k] != '\"')
                {
                    s_icon += s_json[k];
                    k++;
                }
                break;
            }
        }
        int b = S_html.find("{list.weather.icon}");
        S_html.erase(b, 19);
        S_html.insert(b, s_icon);
        k = s_json.find("\"dt_txt\"", k);
        if (k == -1 || day == 5) {
            break;
        }
        k += 9;
    }
    return S_html;
}

// В этой функции формируем ответ сервера на запрос
void gen_response(const Request& req, Response& res) {
    // Команда set_content задаёт ответ сервера и тип ответа:
    // Hello, World! - тело ответа
    // text/plain - тип ответа (в данном случае обычный текст)
    res.set_content(GetWeather(), "text/html");
}

int main() {
    Server svr;                    // Создаём сервер (пока-что не запущен)
    svr.Get("/", gen_response);    // Вызвать функцию gen_response если кто-то обратиться к корню "сайта"
    svr.listen("localhost", 3000); // Запускаем сервер на localhost и порту 1234
}
```
<br> 

3. Скриншот:
<center>
<img src="Screnshot\1.PNG"><br>
Рис. 1. Заполненый шаблон</center>

**Вывод:** Я ознакомился с написанием сервера и клиета, сервисом openweathermap.org, а также Json.