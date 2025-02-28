
## API Reference

#### HttpLauncher Class

```
  #include "./HttpLauncher/HttpLauncher.h"
```

| Method | Type     | Description                | Access |
| :-------- | :------- | :------------------------- | :------|
| **HttpLauncher**(int port) | `void` | Constructor your laucnher with port | public |
| **HttpLauncher**() | `void` | Constructor your laucnher without port | public |
| **~HttpLauncher**() | `void` | Destructor your laucnher without port | public |
| **getPort**() | `int` | Get server port | public |
| **setPort**(int port) | `void` | Set server port | public |
| **setPort**(int port) | `void` | Set server port | public |
| **launch**() | `void` | Launches the database to work with the server | public |
| **getIp**(sockaddr& addr) | `std::string` | Get IP of running server | private |
