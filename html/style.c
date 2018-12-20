#include <sys/types.h> /* size_t, ssize_t */
#include <stdarg.h> /* va_list */
#include <stddef.h> /* NULL */
#include <stdint.h> /* int64_t */
#include <kcgi.h>

int main(void) {
    struct kreq r;
    const char *page = "index";
    if (KCGI_OK != khttp_parse(&r, NULL, 0, &page, 1, 0))
        return 0;
    khttp_head(&r, kresps[KRESP_STATUS],
        "%s", khttps[KHTTP_200]);
    khttp_head(&r, kresps[KRESP_CONTENT_TYPE],
        "%s", kmimetypes[KMIME_TEXT_CSS]);
    khttp_body(&r);
    khttp_puts(&r,"    /*general styles*/\
    body {\
      font: normal 18px/1.5 'Fira Sans', 'Helvetica Neue', sans-serif;\
      background: #3AAFAB;\
      color: #fff;\
      padding: 50px 0;\
    }\
    #container {\
      width: 80%;\
      max-width: 1200px;\
      margin: 0 auto;\
    }\
    .container * {\
      box-sizing: border-box;\
    }\
    /*index.html*/\
    form{\
      margin: auto;\
    }\
    .flex-outer{\
    	padding: 0;\
    	  max-width: 800px;\
      margin: auto;\
    }\
    .flex-outer li{\
    	display: flex;\
    	flex-wrap: wrap;\
    	  align-items: center;\
      justify-content: center;\
    	vertical-align: middle;\
    	margin: auto;\
    }\
    .flex-outer > li > label{\
    	flex: 1 0 120px;\
     	max-width: 400px;\
     	  padding: 8px;\
      font-weight: 300;\
      letter-spacing: .09em;\
      text-transform: uppercase;\
    }\
    .flex-outer > li > input{\
    	flex: 1 0 10px;\
    	padding: 5px;\
      border: none;\
      max-width: 20%;\
    }\
    .flex-outer li button {\
      margin: auto;\
      margin-top: 15px;\
      padding: 8px 16px;\
      border: none;\
      background: #333;\
      color: #f2f2f2;\
      text-transform: uppercase;\
      letter-spacing: .09em;\
      border-radius: 2px;\
    }\
    /*loading page*/\
    #loading_text{\
      margin: auto;\
      text-align: center;\
      margin-top: 200px;\
      max-width: 50%;\
    }\
    #text1{\
        font-size: 40px;\
    }\
    #text2{\
        font-size: 20px;\
    }\
    .loader{\
      border: 5px solid #3AAFAB;\
      border-top: 5px solid #f3f3f3;\
      border-right: 5px solid #f3f3f3;\
      border-radius: 50%;\
      width: 30px;\
      height: 30px;\
      margin: auto;\
      animation: spin 2s linear infinite;\
    }\
    @keyframes spin {\
      0% { transform: rotate(0deg); }\
      100% { transform: rotate(360deg); }\
    }\
    #start_time{\
      margin-top: 20px;\
        font-size: 15px;\
    }    ");
    khttp_free(&r);
    return 0;
}
