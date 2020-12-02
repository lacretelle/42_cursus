<?php
class Router {
  private $_ctrler;
  private $_view;
  private $_request;

  public function __construct(){
    $this->_request = new Request();
  }

  public function route(){
    $path = explode('/', filter_var($this->_request->path, FILTER_SANITIZE_URL));
    $url = array_slice($path, 1);
    if (empty($url[0])) {
      header("Location:".WEBROOT."home/index");
      exit();
    } else {
      $controller = ucfirst(strtolower($url[0]));
    }
    $action = empty($url[1]) ? 'index' : $url[1];
    $params = array_slice($url, 2);
    $controllerClass = $controller.'Controller';
    $controllerFile = ROOT.'controllers/'.$controllerClass.'.php';
    if (file_exists($controllerFile)) {
      require($controllerFile);
      $this->_ctrler = new $controllerClass();
    } else {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    if(!method_exists($controllerClass, $action)){
      header("Location:".WEBROOT."home/page404");
      exit();
      }
    $this->_ctrler->$action($params);
  }
}
