#include "weatherapi_client.h"

int main() {
  WeatherApiClient weather("2746d79fc5fe4b7595f100844240105");
  Weather_Request_T req;
  req.method = API_Method_T::kCurrent;
  req.xml = true;
  req.lang = "ru";
  req.q = "Ташкент";

  std::cout << weather.MakeRequest(req) << std::endl;
  return 0;
}