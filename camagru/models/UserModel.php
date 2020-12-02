<?php

class UserModel extends Model{
  function getAllUsers(){
    $req = $this->_pdo->prepare("SELECT * FROM user");
    $req->execute();
    $res = $req->fetchAll(PDO::FETCH_ASSOC);
    return ($res);
  }
  function findUserToken($token){
    $req = $this->_pdo->prepare("SELECT * FROM user WHERE `token` = :token");
    $data = array('token' => $token);
    $req->execute($data);
    $res = $req->fetch(PDO::FETCH_ASSOC);
    return ($res);
  }

  function signin($username, $mail, $birth, $pass, $country, $city, $token){
    if (is_null($city))
    {
      $req = $this->_pdo->prepare("INSERT INTO `user`(`username`, `email`, `password`, `birthday`, `country`,`notification`, `token`) VALUES(:username, :email, :pass, :birthday, :country, 1, :token)");
      $data = array('username' => $username, 'email' => $mail, 'pass' => $pass, 'birthday' => $birth, 'country' => $country, 'token' => $token);
    }else {
      $req = $this->_pdo->prepare("INSERT INTO `user`(`username`, `email`, `password`, `birthday`, `country`, `city`, `notification`, `token`) VALUES(:username, :email, :pass, :birthday, :country, :city, 1,:token)");
      $data = array('username' => $username, 'email' => $mail, 'pass' => $pass, 'birthday' => $birth, 'country' => $country, 'city' => $city, 'token' => $token);
    }
    $req->execute($data);
  }

  function valideUser($id) {
    $req = $this->_pdo->prepare("UPDATE `user` SET `validate` = '1' WHERE `id_user`= :id");
    $data = array('id' => $id);
    $req->execute($data);
  }

  function login($identity){
    if (!strstr($identity, "@"))
    {
      $quest = $this->_pdo->prepare("SELECT * FROM user WHERE username = :username");
      $data = array('username' => $identity);
    } else {
      $quest = $this->_pdo->prepare("SELECT * FROM user WHERE email = :mail");
      $data = array('mail' => $identity);
    }
    $quest->execute($data);
    $res = $quest->fetch(PDO::FETCH_ASSOC);
    return($res);
  }

  function updatePass($pass, $id) {
    $quest = $this->_pdo->prepare("UPDATE user SET `password` = :pass WHERE id_user = :id");
    $data = array('pass' => $pass, 'id' => $id);
    $quest->execute($data);
  }

  function updateInfo($id, $username, $mail, $birth, $country, $city,$notif) {
    $q = $this->_pdo->prepare("UPDATE user SET `username` = :username, `email` = :mail, `birthday` = :birth, `country` = :country, `city` = :city, `notification` = :notif WHERE id_user = :id");
    $data = array('username' => $username, 'mail' => $mail, 'birth' => $birth, 'country' => $country, 'city' => $city, 'notif' => $notif ,'id' => $id);
    $q->execute($data);
  }

  function displayUser($id) {
    $req = $this->_pdo->prepare("SELECT * FROM user WHERE id_user = :id");
    $data = array('id' => $id);
    $req->execute($data);
    $res = $req->fetch(PDO::FETCH_ASSOC);
    return ($res);
  }

  function displayImgUser($id) {
    $req = $this->_pdo->prepare("SELECT * FROM `img` WHERE id_user = :id ORDER BY `date_img` DESC");
    $data = array('id' => $id);
    $req->execute($data);
    $res = $req->fetchAll(PDO::FETCH_ASSOC);
    return ($res);
  }
}
