<?php
class Controller {
  public $var = [];

  function render($view){
    extract($this->var);
    ob_start();
    require_once(ROOT."/views/".$view.".php");
    $content = ob_get_clean();
    require_once(ROOT."/views/default.php");
  }

  function loadModel($model) {
    $modelClass = ucfirst($model).'Model';
    require_once(ROOT.'models/'.$modelClass.'.php');
    if (!isset($this->modelClass))
      $this->modelClass = new $modelClass();
    return $this->modelClass;
  }
}
 ?>
