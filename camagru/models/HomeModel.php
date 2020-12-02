<?php

class HomeModel extends Model {

  function nbImg() {
    $q = $this->_pdo->prepare("SELECT COUNT(`id_img`) AS nbImg FROM `img`");
    $q->execute();
    $res = $q->fetch(PDO::FETCH_ASSOC);
    return($res);
  }

  function findImgAll($offset) {
    $q = $this->_pdo->prepare("SELECT * FROM `img` ORDER BY `date_img` DESC LIMIT 5 OFFSET $offset");
    $q->execute();
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function displayLike($id_user) {
    $q = $this->_pdo->prepare("SELECT `id_img` FROM `liked` WHERE `id_user` = :id_user");
    $data = array('id_user' => $id_user);
    $q->execute($data);
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function countLike() {
    $q = $this->_pdo->prepare("SELECT COUNT(`id_liked`) AS 'nbLike', `id_img` FROM `liked` GROUP BY `id_img`");
    $q->execute();
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function countPost() {
    $q = $this->_pdo->prepare("SELECT COUNT(DISTINCT `id_post`) AS 'nbPost', `id_img` FROM `post` GROUP BY `id_img`");
    $q->execute();
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function findAllPost() {
    $q = $this->_pdo->prepare("SELECT `comment`, `id_img`, `username` FROM `post` INNER JOIN `user` ON `post`.`id_author` = `user`.`id_user`");
    $q->execute();
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function addPost($post, $id_img, $id_user, $date_post) {
    $req = $this->_pdo->prepare("INSERT INTO `post`(`comment`, `date_post`,`id_author`, `id_img`) VALUES(:com, :date_post, :id_user, :id_img)");
    $data = array('com' => $post, 'date_post' => $date_post,'id_user' => $id_user, 'id_img' => $id_img);
    $req->execute($data);
  }

  function recordLike($id_user, $id_img) {
    $req = $this->_pdo->prepare("INSERT INTO `liked`(`id_user`, `id_img`) VALUES(:id_user, :id_img)");
    $data = array('id_user' => $id_user, 'id_img' => $id_img);
    $req->execute($data);
  }

  function deleteLike($id_user, $id_img) {
    $req = $this->_pdo->prepare("DELETE FROM `liked` WHERE `id_user` = :id_user AND `id_img` = :id_img");
    $data = array('id_user' => $id_user, 'id_img' => $id_img);
    $req->execute($data);
  }

  function findUserImg($id_img) {
    $req = $this->_pdo->prepare("SELECT * FROM `img` INNER JOIN `user` ON `img`.id_user = `user`.id_user WHERE `id_img` = :id_img");
    $data = array('id_img' => $id_img);
    $req->execute($data);
    $res = $req->fetch(PDO::FETCH_ASSOC);
    return ($res);
  }
}
