<?php

class Request {
  public $path;

  function __construct(){
    $this->path = trim($_SERVER["REQUEST_URI"], '/');
  }
}
