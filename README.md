# Weatherapi_client

Простая хэдерс онли библиотека на языке С++ для работы c api прогноза погоды известного поставщика [weatherapi.com](https://www.weatherapi.com)

Делал ее по фану и надеюсь что в дальейшем она будет полезна разработчикам для легкой интеграции сервиса <i>прогноза погоды</i> в свой проект.
Если в друг у вас есть какие либо предложения или вы нашли ошибку, пожалуйста напишите мне.

К стати в коде [example.cc](https://github.com/robot3human0/weatherapi/blob/main/example.cc) есть мой 'ключ' он обычный бесплатный, который вы сами себе можете сделать зарегистрировавшись на [weatherapi.com](https://www.weatherapi.com). Но если он все еще работает можете его использовать.

Для запросов использовал простенькую библиотеку [<b><i>httplib.h</i></b>](https://github.com/yhirose/cpp-httplib) состаящую из одного заголовочного файла, кторый лежит тут же в каталоге <i><u>src</i></u>.

## Зависимости:
- <b>openssl</b>
- <b>crypto</b>

## Пример сборки на примере <b>example.cc</b> <br>
`g++ -Wall -Werror -Wextra -std=c++11 example.cc -o example_client -lssl -lcrypto`

# Weatherapi_client (project in development)

A simple header-only library in C++ to work with a well-known vendor's weather API. [weatherapi.com](https://www.weatherapi.com)

I made it for fun and I hope that in the future it will be useful for developers to easily integrate the <i>weather forecast</i> service into their project.
If you have any suggestions or find a bug, please write me.

By the way, in the code [example.cc](https://github.com/robot3human0/weatherapi/blob/main/example.cc) there is my 'key', it is a regular free one, which you can make for yourself by registering on [weatherapi.com](https://www.weatherapi.com). But if it still works, feel free to use it.

For http requests I used a simple library [<b><i>httplib.h</i></b>](https://github.com/yhirose/cpp-httplib) consisting of one header file, which is located right there in <i><u>src</i></u> directory.

## Dependencies:
- <b>openssl</b>
- <b>crypto</b>

## Compile example using <b>example.cc</b><br>
`g++ -Wall -Werror -Wextra -std=c++11 example.cc -o example_client -lssl -lcrypto`


# Code example
```
...

// WeatherApiClient weather("your key"); // Create an object with key
WeatherApiClient weather;                // Or without
weather.SetKey("your key");              // Set your key to an object

Weather_Request_T req;                   // struct keeping flags to pass them in request
req.method = API_Method_T::kHistory;     // All methods see on weather weatherapi.com
req.xml = true;                          // false by default and answer will be as json string
req.lang = "ru";                         // Language
req.q = "Ташкент";                       // all parameters you can find on the weatherapi.com
req.aqi = 1;                             // or in comments in the code.
req.hour = 17;                           //
req.dt = "2024-01-24";                   //
req.end_dt = "2024-02-03";               //

std::string answer = weather.MakeRequest(req); // answer from server as xml or json string format

...
```