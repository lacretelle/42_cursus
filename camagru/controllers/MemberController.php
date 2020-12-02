<?php
class MemberController extends Controller{

  function home($p) {
    if (!empty($p)) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    $model = $this->loadModel('member');
    $this->render('member');
  }

  function webcam($p) {
    if (!empty($p)) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    $model = $this->loadModel('member');
    $this->var = $model->findAllStage();
    $this->tab = $model->findImg($_SESSION['id']);
    $this->render('webcam');
  }

  function load($p) {
    if (!empty($p)) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    $model = $this->loadModel('member');
    $this->var = $model->findAllStage();
    $this->tab = $model->findImg($_SESSION['id']);
    $this->render('load');
  }

  function capture() {
    $model = $this->loadModel('member');
    $id_user = $_SESSION['id'];
    $username = $_SESSION['username'];
    $nb = $model->nb_img($id_user);
    $date = date('Y-m-d H:i:s');

    if (isset($_POST) && !empty($_POST)) {
      $path = md5($id_user.$username).($nb + 2).".jpg";
      $target_dir = "public/img/upload/";
      $stage = $_POST['stage'];
      $id_stage = $_POST['id_stage'];
      $data = $_POST['data'];
      $title_img = null;
      if (isset($_POST['title_img'])) {
        $title_img = htmlspecialchars($_POST['title_img']);
      }
    if (preg_match('/^data:image\/(\w+);base64,/', $data) && preg_match('/^data:image\/(\w+);base64,/', $stage)) {

          $image_parts = explode(';base64,', $data);
          $image_type_aux = explode("image/", $image_parts[0]);
          $image_type = base64_decode($image_parts[1]);
          $stage_parts = explode('base64,', $stage);
          $tmp_stage = $stage_parts[1];
          $data_stage = base64_decode($tmp_stage);
          $dest = imagecreatefromstring($image_type);
          $src = imagecreatefromstring($data_stage);
          imagecopy($dest, $src, 0, 0, 0, 0, 2000, 2000);
          header('Content-Type: image/jpeg');
          imagejpeg($dest, $target_dir.$path);
          if ($title_img == null)
          {
            $title_img = "Fait le ".$date.", par ".$username;
          }
          $model->recordPic($title_img, $target_dir.$path, $id_stage, $id_user, $date);
          imagedestroy($dest);
          imagedestroy($src);
          echo ($target_dir.$path);
          exit();
      } else {
          throw new \Exception('did not match data URI with image data');
      }
    }
  }

  function delete_img($id) {
    $model = $this->loadModel('member');
    if (isset($id[0])) {
      $id_img = $id[0];
      if ($model->delete_img($id_img) == 1) {
        header("Location:".WEBROOT."user/account/".$_SESSION['id']."");
      }
    } else {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
  }

  function delete_all($id) {
    $model = $this->loadModel('member');
    if (isset($id[0])) {
      $model->delete_all($id[0]);
      header("Location:".WEBROOT."user/account/".$id[0]."");
    } else {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
  }
}
