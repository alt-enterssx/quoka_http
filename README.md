
## API Reference

#### Launcher Class

```
  #include "./HttpLauncher/HttpLauncher.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
| **HttpLauncher**(int port) | `constructor` | Constructor your laucnher with port | `public` |
| **HttpLauncher**() | `constructor` | Constructor your laucnher without port | `public` |
| **~HttpLauncher**() | `destructor` | Destructor your laucnher  | `public` |
| **getPort**() | `int` | Get server port | `public` |
| **setPort**(int port) | `void` | Set server port | `public` |
| **setPort**(int port) | `void` | Set server port | `public` |
| **launch**() | `void` | Launches the database to work with the server | `public` |
| **getIp**(sockaddr& addr) | `std::string` | Get IP of running server | `private` |

#### Listener Class

```
  #include "./HttpListener/HttpListener.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**HttpListener**(SOCKET& lSock) | `constructor` | Constructor your listener with port | `public` |
|**~HttpListener**() | `destructor` | Destructor your listener | `public` |
|**listen**() | `void` | Start accepting requests from a socket | `public` |
|**close**() | `void` | Stop accepting requests from a socket | `public` |

#### Router Class

```
  #include "./HttpRouter/HttpRouter.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
| **HttpRouter**() | `constructor` | Empty Constructor for routing | `public`
| **route**(HttpRequest::Request req, SOCKET& cSock) | `void` | Receives a request and determines its implementation function | `public`
| **GET_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `void` | Adds the implementation function to the router's memory with the method GET | `public`
| **POST_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method POST | `public`
| **PUT_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method PUT | `public`
| **HEAD_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method HEAD | `public`
| **DELETE_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method DELETE | `public`

#### Request Class

```
  #include "./HttpRequest/HttpRequest.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**parseRequest**(std::string& str) | `HttpRequest::Request` | Creates a request object based on a common query string | `public` |
|**getMethodAsStr**(HttpRequest::MethodType type) | `std::string` | Converts the object HttpRequest::MethodType to a string | `public` |
|**getMethodAsStr**(HttpRequest::MethodType type) | `std::string` | Converts the object HttpRequest::MethodType to a string | `public` |
|**getHeader**(std::vector<Header> headers, HeaderType type) | `HttpRequest::Header` | Looking for a title to work with | `public` |
|**split**(std::string& str, char sym) | `std::vector<std::string>` | Splits a string into a vector (only for working with a generator) | `private` |
|**getHeaderAsEn**(std::string& header) | `HttpRequest::HeaderType` | Based on the string returns HeaderType | `private` |
|**getMethodAsEn**(std::string& method) | `HttpRequest::MethodType` | Based on the string returns MethodType | `private` |
