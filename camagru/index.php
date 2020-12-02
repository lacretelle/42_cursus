<?php
define('ROOT', str_replace('index.php', '', $_SERVER['SCRIPT_FILENAME']));
define('WEBROOT', str_replace('index.php', '', $_SERVER['SCRIPT_NAME']));

session_start();
require_once(ROOT.'config/setup.php');
require_once(ROOT.'core/Request.php');
require(ROOT.'core/Router.php');
require(ROOT.'core/Model.php');
require(ROOT.'core/Controller.php');
date_default_timezone_set('Europe/Paris');
$db = Setup::getNew();
$router = new Router();
$router->route();
