<?php
class MemberModel extends Model {

  function findImg($id) {
    $q = $this->_pdo->prepare("SELECT `path`, `title`, `id_img` FROM `img` WHERE id_user = :id ORDER BY `date_img` DESC LIMIT 5");
    $data = array('id' => $id);
    $q->execute($data);
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function findAllStage() {
    $q = $this->_pdo->prepare("SELECT * FROM `stage`");
    $q->execute();
    $res = $q->fetchAll(PDO::FETCH_ASSOC);
    return($res);
  }

  function recordPic($title, $path, $stage, $id_user, $date) {
    $q = $this->_pdo->prepare("INSERT INTO img(`title`, `path`, `date_img`, `id_stage`, `id_user`) VALUES (:title, :img_path, :date_img, :stage, :id_user)");
    $data = array('title' => $title, 'img_path' => $path, 'date_img' => $date, 'stage' => $stage, 'id_user' => $id_user);
    $q->execute($data);
  }

  function nb_img($id_user) {
    $q = $this->_pdo->prepare("SELECT count(DISTINCT `id_img`) AS 'nb' FROM `img` LEFT JOIN `user` ON img.id_user = user.id_user WHERE img.id_user = :id_user");
    $data = array('id_user' => $id_user);
    $q->execute($data);
    $res = $q->fetch();
    return($res['nb']);
  }

  function findStage($id) {
    $q = $this->_pdo->prepare("SELECT `path` FROM `stage` WHERE id_stage = :id");
    $data = array('id' => $id);
    $q->execute($data);
    $res = $q->fetch();
    return($res['path']);
  }

  function delete_img($id) {
    $q = $this->_pdo->prepare("SELECT * FROM `img` WHERE `id_img` = :id");
    $data = array('id' => $id);
    $q->execute($data);
    $res = $q->fetch(PDO::FETCH_ASSOC);
    if (!is_null($res)) {
      $quest = $this->_pdo->prepare("DELETE FROM `img` WHERE `id_img` = :id");
      $data = array('id' => $id);
      $quest->execute($data);
      return (1);
    }else {
      return (0);
    }
  }

  function delete_all($id) {
    $quest = $this->_pdo->prepare("DELETE FROM `img` WHERE `id_user` = :id");
    $data = array('id' => $id);
    $quest->execute($data);
  }
}
