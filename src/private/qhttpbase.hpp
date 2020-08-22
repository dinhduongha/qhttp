/** base classes for private implementations.
 * https://github.com/azadkuh/qhttp
 *
 * @author amir zamani
 * @version 2.0.0
 * @date 2014-07-11
 */

#ifndef QHTTPBASE_HPP
#define QHTTPBASE_HPP

#include "qhttpfwd.hpp"

#include "qhttpabstractsocket.hpp"
#include "qhttpheaders.hpp"

#include <QBasicTimer>
#include <QHostAddress>

#include "http-parser/http_parser.h"

///////////////////////////////////////////////////////////////////////////////
namespace qhttp {
namespace details {
///////////////////////////////////////////////////////////////////////////////

struct HttpBase {
  QString iversion;
  Headers iheaders;
}; // struct HttpBase

///////////////////////////////////////////////////////////////////////////////

struct HttpRequestBase : public HttpBase {
  QUrl iurl;
  THttpMethod imethod;
}; // HttpRequestBase

///////////////////////////////////////////////////////////////////////////////

struct HttpResponseBase : public HttpBase {
  TStatusCode istatus = ESTATUS_BAD_REQUEST;

  HttpResponseBase() { iversion = "1.1"; }
}; // HttpResponseBase

///////////////////////////////////////////////////////////////////////////////
} // namespace details
} // namespace qhttp
///////////////////////////////////////////////////////////////////////////////
#endif // QHTTPBASE_HPP
