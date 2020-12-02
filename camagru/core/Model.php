<?php
class Model {
  private $_dbhost;
  private $_dbuser;
  private $_dbpass;
  private $_dbname;
  protected $_pdo = null;

  function __construct(){
    require(ROOT.'config/database.php');
    $tmp = explode(';', $DB_DSN);
    $conf = explode('=', $tmp[1]);
    $this->_dbname = $conf[1];
    $conf = explode('=', $tmp[2]);
    $this->_dbhost = $conf[1];
    $this->_dbuser = $DB_USER;
    $this->_dbpass = $DB_PASSWORD;
    try {
     $this->_pdo = new PDO("mysql:host=$this->_dbhost;dbname=$this->_dbname;charser=utf8", $this->_dbuser, $this->_dbpass);
      $this->_pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch(PDOException $e){
      die('DB ERROR: '. $e->getMessage());
    }
  }
}
?>
