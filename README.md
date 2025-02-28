
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
