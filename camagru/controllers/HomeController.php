<?php
class HomeController extends Controller {

  function index($param) {
    if (isset($param[0])) {
      if ($param[0] == "forgotpass") {
        $this->message = "Un mail vient de t'être envoyé pour modifier ton mot de passe.";
      } else {
        header("Location:".WEBROOT."home/page404");
        exit();
      }
    }
    $this->render('index');
  }

  function manageLike() {
    $id_img = $_POST['id_img'];
    $action = $_POST['action'];
    $id_user = $_SESSION['id'];
    $model = $this->loadModel('Home');
    $nblike = $_POST['nblike'];
    if (!empty($id_user) && isset($id_img)) {
      if ($action == "add") {
        $model->recordLike($id_user, $id_img);
        $nblike += 1;
      }elseif ($action == "delete") {
        $model->deleteLike($id_user, $id_img);
        $nblike -= 1;
      }
    }
    echo $nblike;
  }

  function gallery($c) {
    $model = $this->loadModel('home');
    $nbImg = $model->nbImg()['nbImg'];
    $this->nbLike = $model->countLike();
    $this->nbPost = $model->countPost();
    $this->allPost = $model->findAllPost();
    if (isset($_SESSION['id'])) {
      $id_user = $_SESSION['id'];
      $this->likes = $model->displayLike($id_user);
    }
    if (empty($c)) {
      header("Location:".WEBROOT."home/gallery/1");
      exit();
    }
    if (is_numeric($c[0])) {
      $i = intval($c[0]) - 1;
      if ($i < 0) {
        header("Location:".WEBROOT."home/gallery/1");
        exit();
      } elseif ($i > ($nbImg % 5)) {
        echo "limit sup";
        header("Location:".WEBROOT."home/gallery/".($nbImg % 5 + 1));
        exit();
      }
      $i = $i * 5;
    }
    $this->page = $i / 5 + 1;
    $this->page_max = intval($nbImg / 5 + 1);
    $this->var = $model->findImgAll($i);
    $this->render('gallery');
  }

  function mailPost($author, $mail, $title, $name) {
    $to = $mail;
    $subject = "Commentaires sur votre photo";
    $message = "Bonjour ".$author.",\r\nUn utilisateur: ".$name.", vient de commenter ta photo, ".$title;
    mail($mail, $subject, $message);
  }

  function addPost() {
    $model = $this->loadModel('home');
    $author = $model->findUserImg($_POST['id_img']);
    $nbpost = $_POST['nbpost'];
    if (isset($_POST['post']) && isset($_SESSION['id']) && isset($_POST['id_img'])) {
      $nbpost += 1;
      $date = date('Y-m-d H:i:s');
      $res = $model->addPost($_POST['post'], $_POST['id_img'],$_SESSION['id'], $date);
      if ($author['notification']) {
        $this->mailPost($author['username'], $author['email'], $author['title'], $_SESSION['username']);
      }
    }
    echo $nbpost;
  }

  function page404() {
    $this->render('404');
  }
}
