#ifndef DATA_H
#define DATA_H

#include <string>

struct Answer_T {
  std::string city;
  std::string country;
  std::string region;
  std::string wind_direction;
  std::string condition;
  std::string localtime;
  std::string icon;
  double latitude;
  double longitude;
  double temp_c;
  double temp_f;
  double feelslike_c;
  double feelslike_f;
  double wind_mph;
  double wind_kph;
  double presure_mb;
  double presure_in;

};

struct Weather_Request_T {
  std::string q;            /* Query parameter based on which data is 
                               sent back. It could be following:

                               Latitude and Longitude (Decimal degree) e.g: q=48.8567,2.3508
                               city name e.g.: q=Paris
                               US zip e.g.: q=10001
                               UK postcode e.g: q=SW1
                               Canada postal code e.g: q=G2J
                               metar:<metar code> e.g: q=metar:EGLL
                               iata:<3 digit airport code> e.g: q=iata:DXB
                               auto:ip IP lookup e.g: q=auto:ip
                               IP address (IPv4 and IPv6 supported) e.g: q=100.0.0.1
                               By ID returned from Search API. e.g: q=id:2801268
                               bulk */

  std::string days;         /* Required only with forecast API method. 	

                               Number of days of forecast required.

                               days parameter value ranges between 1 and 14. e.g: days=5

                               If no days parameter is provided then only today's weather 
                               is returned. */

  std::string dt;           /* Required for History and Future API

                               Restrict date output for Forecast and History API method.
                     
                               For history API 'dt' should be on or after 1st Jan, 
                               2010 in yyyy-MM-dd format (i.e. dt=2010-01-01)
                     
                               For forecast API 'dt' should be between today and 
                               next 14 day in yyyy-MM-dd format (i.e. dt=2010-01-01)
 
                               For future API 'dt' should be between 14 days and 300 days 
                               from today in the future in yyyy-MM-dd format
                               (i.e. dt=2023-01-01) */

  std::string unixdt;       /* Optional

                               Unix Timestamp used by Forecast and History API method.

                               unixdt has same restriction as 'dt' parameter. Please either 
                               pass 'dt' or 'unixdt' and not both in same request.
                               e.g.: unixdt=1490227200 */

  std::string end_dt;       /* Optional : Availiable for History API
                               Only works for API on PRO plan and above

                               Restrict date output for History API method.
                          
                               For history API 'end_dt' should be on or after 1st Jan,
                               2010 in yyyy-MM-dd format (i.e. dt=2010-01-01)

                               'end_dt' should be greater than 'dt' parameter and
                               difference should not be more than 30 days between the two dates. */

  std::string unixend_dt;   /* Optional

                               Unix Timestamp used by History API method.

                               unixend_dt has same restriction as 'end_dt' parameter.
                               Please either pass 'end_dt' or 'unixend_dt' and not both
                               in same request. e.g.: unixend_dt=1490227200 */

  std::string hour;         /* Optional

                               Restricting forecast or history output to a specific hour in a given day.

                               Must be in 24 hour. For example 5 pm should be hour=17, 6 am as hour=6 */

  std::string alerts;       /* Optional

                               Disable alerts in forecast API output

                               alerts=yes or alerts=no */

  std::string aqi;          /* Optional

                               Enable/Disable Air Quality data in forecast API output

                               aqi=yes or aqi=no */

  std::string tides;        /* Optional

                               Enable/Disable Tide data in Marine API output 	

                               tides=yes or tides=no */

  std::string tp;           /* Optional

                               Get 15 min interval data for Forecast and History API. Available for
                               Enterprise clients only.

                               tp=15 */

  std::string solar;        /* Optional
         
                               Enable solar irradiance data in History API. Available for
                               Enterprise clients only. 	

                               solar=yes */

  std::string et0;          /* Optional

                               Enable Evapotranspiration data in History API. Available for 
                               Enterprise clients only. 	

                               et0=yes */

  std::string wind100_mph;  /* Optional
                              
                               Enable wind data and return wind speed in mph at 100mt 
                               height in History API. Available for Enterprise clients only. 	

                               wind100mph=yes */

  std::string wind100_kph;  /* Optional
                               Enable wind data and return wind speed in kmph at 100mt height
                               in History API. Available for Enterprise clients only. 	

                               wind100kph=yes */

  std::string lang;         /* Optional
        
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
  };

#endif  // DATA_H