
## Quoka Library

The Quoka library is designed for building web servers that provide HTTP APIs with request handling and response generation capabilities. It includes components for working with HTTP requests and responses, routing requests, logging, and managing server configurations.
## API Reference

#### Launcher Class

```
  #include "./HttpLauncher/HttpLauncher.h"
```

> The HttpLauncher class initializes and starts an HTTP server on a specified port (default: 8080). It sets up network resources using Winsock, creates a listening socket, and handles incoming connections. It also logs server information and errors. The class provides methods for getting and setting the server port, and throws exceptions (HttpException) for any setup issues.

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

#### Response Class

```
  #include "./HttpResponse/HttpResponse.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**generateResponse**(HttpResponse::Response& resp) | `std::string` | Generates a response to send to the client | `public` |
|**getStatusAsStr**(HttpResponse::StatusType& type) | `std::string` | Сonverts object HttpResponse::StatusType to string | `private` |
|**getHeaderAsStr**(HeaderType& type) | `std::string` | Сonverts object HttpResponse::HeaderType to string | `private` |

#### Logger Class

```
  #include "./HttpLogger/HttpLogger.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**log**(const std::string& logStr, LoggerType type) | `void` | Sends log to console taking into account enum and string | `public` |

#### Confih Class

```
  #include "./ServerProperties/ServerProperties.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**ServerProperties**() | `constructor` | Empty constructor for config | `public` |
|**setFile**(std::ifstream& fileR) | `void` | Accepts a .prop file to read its values | `public` |
|**getProperty**(const std::string& str) | `std::string` | Gets a value from memory | `public` |
