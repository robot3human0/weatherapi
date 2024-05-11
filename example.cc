#include "src/weatherapi_client.h"

int main() {
  WeatherApiClient weather("2746d79fc5fe4b7595f100844240105");
  Weather_Request_T req;
  req.method = API_Method_T::kHistory;
  // req.xml = true;
  req.lang = "ru";
  req.q = "Ташкент";
  req.aqi = 1;
  req.hour = 1;
  // req.days = 2;
  req.dt = "2024-01-24";
  req.end_dt = "2024-02-03";

  std::cout << weather.MakeRequest(req) << std::endl;
  return 0;
}