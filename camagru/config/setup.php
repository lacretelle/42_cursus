<?php
class Setup {
  private $_dbhost;
  private $_dbname;
  private $_dbuser;
  private $_dbpass;
  private static $_newDb = null;

  public static function getNew(){
    if (!self::$_newDb){
      self::$_newDb = new Setup();
    }
    return self::$_newDb;
  }
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
      self::$_newDb = new PDO("mysql:host=$this->_dbhost", $this->_dbuser, $this->_dbpass);
      self::$_newDb->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
      $sql = file_get_contents(ROOT.'config/camagru.sql');
      self::$_newDb->exec($sql);
    } catch(PDOException $e){
      die('DB ERROR: '. $e->getMessage());
    }
  }
}
