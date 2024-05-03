## Weatherapi_client (проект в разработке)

Предпологается простая библиотека на языке С++ для работы c api прогноза погоды известного поставщика [weatherapi.com](https://www.weatherapi.com)

Делаю ее по фану и надеюсь что в дальейшем она будет полезна разработчикам для легкой интеграции сервиса <i>прогноза погоды</i> в свой проект.

<u>Зависимости:</u>
- <b>openssl</b>
- <b>crypto</b>

для запросов использовал простенькую библиотеку [<b><i>httplib.h</i></b>](https://github.com/yhirose/cpp-httplib) состаящую из одного заголовочного файла, кторый лежит тут же в каталоге <i><u>src</i></u>.

## Сборка
Сборка на примере приложения <b>console_weather_*</b> исходный код лежит в папке в папке concole_weather_app, а сама сборка в <i><u>concole_weather_app/bin</i></u> <br>

Пример (подрузамевается что вы находитесь в каталоге concole_weather_app):<br>
`g++ -std=c++11 console_weather.cc -o console_weather_app -lssl -lcrypto`
