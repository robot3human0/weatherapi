#ifndef WEATHERAPI_CLIENT_H
#define WEATHERAPI_CLIENT_H

#define CPPHTTPLIB_OPENSSL_SUPPORT

#include "httplib/httplib.h"
#include <string>

struct API_Method_T {
  enum E {
    kCurrent = 1,
    kForecast,
    kSearch,
    kHistory,
    kMarine,
    kFuture,
    kTimeZone,
    kSports,
    kAstronomy,
    kIP
  };

  static inline std::string MethodAsString(const int val) {
    switch (val) {
    case API_Method_T::kCurrent  : return "/current";
    case API_Method_T::kForecast : return "/forecast";
    case API_Method_T::kSearch   : return "/search";
    case API_Method_T::kHistory  : return "/history";
    case API_Method_T::kMarine   : return "/marine";
    case API_Method_T::kFuture   : return "/future";
    case API_Method_T::kTimeZone : return "/timezone";
    case API_Method_T::kSports   : return "/sports";
    case API_Method_T::kAstronomy: return "/astronomy";
    case API_Method_T::kIP       : return "/ip";

    default : return "UNKNOWN";
    }
  }
};

struct Weather_Request_T {
  int method;              /* enum Current, Forecast, Search, History etc.*/
  bool xml;                /* response type if false json string */
  std::string q;           /* Query parameter based on which data is
                              sent back. It could be following:

                              Latitude and Longitude (Decimal degree) e.g:
                              q=48.8567,2.3508 city name e.g.: q=Paris US zip e.g.:
                              q=10001 UK postcode e.g: q=SW1 Canada postal code e.g: q=G2J
                              metar:<metar code> e.g: q=metar:EGLL
                              iata:<3 digit airport code> e.g: q=iata:DXB
                              auto:ip IP lookup e.g: q=auto:ip
                              IP address (IPv4 and IPv6 supported) e.g: q=100.0.0.1
                              By ID returned from Search API. e.g: q=id:2801268
                              bulk */

  unsigned short days;     /* Required only with forecast API method.

                              Number of days of forecast required.

                              days parameter value ranges between 1 and 14. e.g: days=5

                              If no days parameter is provided then only today's weather
                              is returned. */

  std::string dt;          /* Required for History and Future API

                              Restrict date output for Forecast and History API method.

                              For history API 'dt' should be on or after 1st Jan,
                              2010 in yyyy-MM-dd format (i.e. dt=2010-01-01)

                              For forecast API 'dt' should be between today and
                              next 14 day in yyyy-MM-dd format (i.e. dt=2010-01-01)

                              For future API 'dt' should be between 14 days and 300 days
                              from today in the future in yyyy-MM-dd format
                              (i.e. dt=2023-01-01) */

  std::string unixdt;      /* Optional

                              Unix Timestamp used by Forecast and History API method.

                              unixdt has same restriction as 'dt' parameter. Please
                              either pass 'dt' or 'unixdt' and not both in same
                              request. e.g.: unixdt=1490227200 */

  std::string end_dt;      /* Optional : Availiable for History API
                              Only works for API on PRO plan and above

                              Restrict date output for History API method.

                              For history API 'end_dt' should be on or after 1st Jan,
                              2010 in yyyy-MM-dd format (i.e. dt=2010-01-01)

                              'end_dt' should be greater than 'dt' parameter and
                              difference should not be more than 30 days between the
                              two dates. */

  std::string unixend_dt;  /* Optional

                              Unix Timestamp used by History API method.

                              unixend_dt has same restriction as 'end_dt' parameter.
                              Please either pass 'end_dt' or 'unixend_dt' and not both
                              in same request. e.g.: unixend_dt=1490227200 */

  unsigned short hour;     /* Optional

                              Restricting forecast or history output to a specific
                              hour in a given day.

                              Must be in 24 hour. For example 5 pm should be
                              hour=17, 6 am as hour=6 */

  short alerts;            /* Optional

                              Disable alerts in forecast API output

                              alerts=yes or alerts=no */

  short aqi;               /* Optional

                              Enable/Disable Air Quality data in forecast API output

                              aqi=yes or aqi=no */

  short tides;             /* Optional

                              Enable/Disable Tide data in Marine API output

                              tides=yes or tides=no */

  bool tp;                 /* Optional

                              Get 15 min interval data for Forecast and History API. Available
                              for Enterprise clients only.

                              tp=15 */

  bool solar;              /* Optional

                              Enable solar irradiance data in History API. Available for
                              Enterprise clients only.

                              solar=yes */

  bool et0;                /* Optional

                              Enable Evapotranspiration data in History API. Available for
                              Enterprise clients only.

                              et0=yes */

  bool wind100_mph;        /* Optional

                              Enable wind data and return wind speed in mph at 100mt
                              height in History API. Available for Enterprise clients
                              only.

                              wind100mph=yes */

  bool wind100_kph;        /* Optional
                              Enable wind data and return wind speed in kmph at 100mt
                              height in History API. Available for Enterprise clients
                              only.

                              wind100kph=yes */

  std::string lang;        /* Optional

                              Returns 'condition:text' field in API in the desired language

                              Please pass 'lang code' from below table. e.g.: lang=fr

                              Language 	          lang code
                              Arabic 	            ar
                              Bengali 	            bn
                              Bulgarian 	          bg
                              Chinese Simplified 	zh
                              Chinese Traditional 	zh_tw
                              Czech 	              cs
                              Danish 	            da
                              Dutch 	              nl
                              Finnish 	            fi
                              French 	            fr
                              German 	            de
                              Greek 	              el
                              Hindi 	              hi
                              Hungarian 	          hu
                              Italian 	            it
                              Japanese 	          ja
                              Javanese 	          jv
                              Korean 	            ko
                              Mandarin 	          zh_cmn
                              Marathi 	            mr
                              Polish 	            pl
                              Portuguese 	        pt
                              Punjabi 	            pa
                              Romanian 	          ro
                              Russian 	            ru
                              Serbian 	            sr
                              Sinhalese 	          si
                              Slovak 	            sk
                              Spanish 	            es
                              Swedish 	            sv
                              Tamil 	              ta
                              Telugu 	            te
                              Turkish 	            tr
                              Ukrainian 	          uk
                              Urdu 	              ur
                              Vietnamese 	        vi
                              Wu (Shanghainese) 	  zh_wuu
                              Xiang 	              zh_hsn
                              Yue (Cantonese) 	    zh_yue
                              Zulu 	              zu */

  Weather_Request_T()
      : method(0)
      , xml(0)
      , days(0)
      , hour(0)
      , alerts(-1)
      , aqi(-1)
      , tides(-1)
      , tp(0)
      , solar(0)
      , et0(0)
      , wind100_mph(0)
      , wind100_kph(0)
      {}

  std::string CheckDays(bool marine) {
    if (marine) {
      if (days < 0) { days = 0; }
      if (days > 7) { days = 7; }
      return "&days=" + std::to_string(days);
    }
    if (14 > days > 0) { return "&days=" + std::to_string(days); }
    return "";
  }

  std::string CheckHour() {
    if (24 > hour > 0) { return "&hour=" + std::to_string(hour); }
    return "";
  }
}; // struct Weather_Request_T

static inline std::string YesOrNo(const bool val) { return val ? "yes" : "no"; }

class WeatherApiClient {
public:
  WeatherApiClient() : client_("https://api.weatherapi.com") {}

  WeatherApiClient(const std::string key)
      : client_("https://api.weatherapi.com"), key_(key) {}

  WeatherApiClient(const WeatherApiClient &o) = delete;

  WeatherApiClient(WeatherApiClient &&o) = delete;

  ~WeatherApiClient() {}

  WeatherApiClient &operator=(const WeatherApiClient &o) = delete;
  WeatherApiClient &operator=(WeatherApiClient &&o) = delete;

  std::string GetKey() const { return key_; }
  bool SetKey(const std::string key) {
    if (!key.empty()) {
      key_ = key;
      return 1; // SUCCESS
    }

    return 0; // FAIL
  }

  std::string MakeRequest(Weather_Request_T &req) {
    std::string response_str;
    std::string parameters = GetParametersString(req);
    std::string request_str =
        ("/v1" + API_Method_T::MethodAsString(req.method) +
         (req.xml ? ".xml" : ".json") + "?key=" + key_ + parameters);

    auto resp = client_.Get(request_str);

    if (resp.error() == httplib::Error::Success) {
      response_str = resp.value().body;
    }

    return response_str;
  }

private:
  std::string GetParametersString(Weather_Request_T &req) {
    bool dt_flag = false;
    bool unix_dt_flag = false;
    std::string result{"&q=" + req.q +
                       (req.lang.empty() ? "" : "&lang=" + req.lang)};
    if (req.method == API_Method_T::kCurrent) {
      if (req.aqi != -1) { result += "&aqi=" + YesOrNo(req.aqi); }
    }

    if (req.method == API_Method_T::kForecast) {
      if (req.aqi != -1)    { result += "&aqi=" + YesOrNo(req.aqi);       }
      if (req.hour)         { result += req.CheckHour();                  }
      if (req.alerts != -1) { result += "&alerts=" + YesOrNo(req.alerts); }
      if (req.days)         { result += req.CheckDays(false);             }
      if (req.tp)           { result += "&tp=15";                         }
      if (!req.dt.empty()) {
        result += "&dt=" + req.dt;
        dt_flag = true;
      }
      if (!req.unixdt.empty() && !dt_flag) {
        result += "&unixdt=" + req.unixdt;
        unix_dt_flag = true;
      }
    }

    if (req.method == API_Method_T::kFuture) {
      if (req.hour) { result += req.CheckHour(); }
      if (!req.dt.empty()) {
        result += "&dt=" + req.dt;
        dt_flag = true;
      }
      if (!req.unixdt.empty() && !dt_flag) {
        result += "&unixdt=" + req.unixdt;
        unix_dt_flag = true;
      }
    }

    if (req.method == API_Method_T::kTimeZone ||
        req.method == API_Method_T::kSports ||
        req.method == API_Method_T::kSearch ||
        req.method == API_Method_T::kIP) {
    }

    if (req.method == API_Method_T::kAstronomy) {
      if (!req.dt.empty()) {
        result += "&dt=" + req.dt;
        dt_flag = true;
      }
      if (!req.unixdt.empty() && !dt_flag) { // need to check up
        result += "&unixdt=" + req.unixdt;
        unix_dt_flag = true;
      }
    }

    if (req.method == API_Method_T::kMarine) {
      if (!req.dt.empty()) {
        result += "&dt=" + req.dt;
        dt_flag = true;
      }
      if (!req.unixdt.empty() && !dt_flag) {
        result += "&unixdt=" + req.unixdt;
        unix_dt_flag = true;
      }
      if (req.tides > -1 && req.method == API_Method_T::kMarine) {
        result += "&tides=" + YesOrNo(req.tides); 
      }
      if (req.hour) { result += req.CheckHour();     }
      if (req.days) { result += req.CheckDays(true); }
    }

    if (req.method == API_Method_T::kHistory) {
      if (!req.dt.empty()) {
        result += "&dt=" + req.dt;
        dt_flag = true;
      }
      if (!req.end_dt.empty() && dt_flag) {
        result += "&end_dt=" + req.end_dt;
      }
      if (!req.unixdt.empty() && !dt_flag) {
        result += "&unixdt=" + req.unixdt;
        unix_dt_flag = true;
      }
      if (!req.unixend_dt.empty() && unix_dt_flag) { result += "&unixend_dt=" + req.unixend_dt;  }
      if (req.hour)                                { result += req.CheckHour();                  }
      if (req.alerts != -1)                        { result += "&alerts=" + YesOrNo(req.alerts); }
      if (req.tp)                                  { result += "&tp=15";                         }
      if (req.solar)                               { result += "&solar=yes";                     }
      if (req.et0)                                 { result += "&et0=yes";                       }
      if (req.wind100_mph)                         { result += "&wind100mph=yes";                }
      if (req.wind100_kph)                         { result += "&wind100kph=yes";                }
      if (req.days)                                { result += req.CheckDays(false);             }
    }

    return result;
  }

  httplib::Client client_;
  std::string key_;

}; // class Engine

#endif // WEATHERAPI_CLIENT_H