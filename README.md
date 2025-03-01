
## Quoka Library

The Quoka library is designed for building web servers that provide HTTP APIs with request handling and response generation capabilities. It includes components for working with HTTP requests and responses, routing requests, logging, and managing server configurations.

![Logo](./img/placeholder.png)

## Support creativity
[![Donation Alerts](https://img.shields.io/badge/Donation%20Alerts-F7DF1E?style=for-the-badge&logo=paypal&logoColor=white&color=yellow)](https://www.donationalerts.com/r/altenter)

## API Reference

### Launcher Class

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

### Listener Class

```
  #include "./HttpListener/HttpListener.h"
```

>The HttpListener class handles incoming client connections, receives HTTP requests, and routes them for processing. It manages socket operations, including accepting connections, reading request data, and handling errors. The class uses a configurable buffer for receiving data and integrates with the HttpRouter to process and respond to requests. It also logs errors and ensures proper cleanup of resources after usage.

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**HttpListener**(SOCKET& lSock) | `constructor` | Constructor your listener with port | `public` |
|**~HttpListener**() | `destructor` | Destructor your listener | `public` |
|**listen**() | `void` | Start accepting requests from a socket | `public` |
|**close**() | `void` | Stop accepting requests from a socket | `public` |

### Router Class

```
  #include "./HttpRouter/HttpRouter.h"
```

>The HttpRouter class is responsible for handling different HTTP methods (GET, POST, PUT, HEAD, DELETE) for specified URLs. It routes requests to appropriate functions and manages these routes in a static map. If a route is found, it sends the corresponding response; otherwise, it sends a default response.

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
| **HttpRouter**() | `constructor` | Empty Constructor for routing | `public`
| **route**(HttpRequest::Request req, SOCKET& cSock) | `void` | Receives a request and determines its implementation function | `public`
| **GET_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `void` | Adds the implementation function to the router's memory with the method GET | `public`
| **POST_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method POST | `public`
| **PUT_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method PUT | `public`
| **HEAD_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method HEAD | `public`
| **DELETE_M**(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) | `constructor` | Adds the implementation function to the router's memory with the method DELETE | `public`

### Request Class

```
  #include "./HttpRequest/HttpRequest.h"
```

>The HttpRequest class handles HTTP requests. It has enumerations for HTTP methods (GET, POST, PUT, HEAD, DELETE) and header types (e.g., ACCEPT, CONTENT_TYPE, HOST). There are also structures for headers and request bodies, supporting various data formats (JSON, HTML, text).
The class implements parsing of a request string into a Request structure, as well as conversion between methods and headers from strings to enumerations.

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**parseRequest**(std::string& str) | `HttpRequest::Request` | Creates a request object based on a common query string | `public` |
|**getMethodAsStr**(HttpRequest::MethodType type) | `std::string` | Converts the object HttpRequest::MethodType to a string | `public` |
|**getMethodAsStr**(HttpRequest::MethodType type) | `std::string` | Converts the object HttpRequest::MethodType to a string | `public` |
| **getHeader**(std::vector&lt;HttpRequest::Header&gt; headers, HeaderType type) | `HttpRequest::Header` | Looking for a title to work with | `public` |
|**split**(std::string& str, char sym) | `std::vector<std::string>` | Splits a string into a vector (only for working with a generator) | `private` |
|**getHeaderAsEn**(std::string& header) | `HttpRequest::HeaderType` | Based on the string returns HeaderType | `private` |
|**getMethodAsEn**(std::string& method) | `HttpRequest::MethodType` | Based on the string returns MethodType | `private` |

### Response Class

```
  #include "./HttpResponse/HttpResponse.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**generateResponse**(HttpResponse::Response& resp) | `std::string` | Generates a response to send to the client | `public` |
|**getStatusAsStr**(HttpResponse::StatusType& type) | `std::string` | Сonverts object HttpResponse::StatusType to string | `private` |
|**getHeaderAsStr**(HttpResponse::HeaderType& type) | `std::string` | Сonverts object HttpResponse::HeaderType to string | `private` |

### Logger Class

```
  #include "./HttpLogger/HttpLogger.h"
```

>The HttpResponse class handles HTTP response generation. It includes enumerations for HTTP response statuses (e.g., OK, NOT_FOUND, INTERNAL_SERVER_ERROR) and header types (e.g., CONTENT_TYPE, LOCATION, SERVER). The class also defines body types (JSON, HTML, IMG) and provides a method for generating an HTTP response string from a Response structure.

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**log**(const std::string& logStr, LoggerType type) | `void` | Sends log to console taking into account enum and string | `public` |

### Config Class

```
  #include "./ServerProperties/ServerProperties.h"
```

>The ServerProperties class loads configuration settings from a file and stores them in a static map. It provides methods to read the file and retrieve properties by their key. If the file can't be opened, it throws an exception.

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
|**ServerProperties**() | `constructor` | Empty constructor for config | `public` |
|**setFile**(std::ifstream& fileR) | `void` | Accepts a .prop file to read its values | `public` |
|**getProperty**(const std::string& str) | `std::string` | Gets a value from memory | `public` |
