

#include <iostream>

#include <rapidjson/document.h>
#include <rapidjson/reader.h>

#include "../weatherapi_client.h"

#define KEY std::string("2746d79fc5fe4b7595f100844240105")

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
  
  WeatherApiClient weather("2746d79fc5fe4b7595f100844240105");
  Weather_Request_T req;

  req.lang = "ru";
  req.q = "Ташкент";

  std::string buff = weather.Current(req);

  // std::cout << buff << "\n\n" << std::endl;

  rapidjson::Document doc;
  doc.Parse(buff.c_str());

  std::string city      = doc["location"]["name"].GetString();
  std::string country   = doc["location"]["country"].GetString();
  std::string condition = doc["current"]["condition"]["text"].GetString();
  std::string wind_dir  = doc["current"]["wind_dir"].GetString();
  double temp_c         = doc["current"]["temp_c"].GetDouble();
  double feels_like_c   = doc["current"]["feelslike_c"].GetDouble();
  double wind_kmph      = doc["current"]["wind_kph"].GetDouble();

  std::cout << "\033[91m" << "The weather in "      << city    << " / " << country << ":"             << "\033[39m" << std::endl;
  std::cout << "\033[93m" << "\t"                   << condition                                                  << "\033[39m" << std::endl;
  std::cout << "\033[92m" << "\ttemperature: - "    << temp_c  << ""                              << "\033[39m" << std::endl;
  std::cout << "\033[94m" << "\tfeels like: - "     << feels_like_c                               << "\033[39m" << std::endl;
  std::cout << "\033[95m" << "\twind direction: - " << wind_dir << ", " << wind_kmph << "kph" << "\033[39m" << std::endl;

  return 0;
}
