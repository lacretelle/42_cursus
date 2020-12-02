<?php
class UserController extends Controller{

  function getUsers(){
    $model = $this->loadModel('User');
    $users = $model->getAllUsers();
    return ($users);
  }

  function findUserToken($token) {
    $model = $this->loadModel('User');
    $user = $model->findUserToken($token);
    return ($user);
  }

  function sendMailSign($token, $mail){
    $to = $mail;
    $subject = "Vérification de votre compte";
    $message = "Bonjour,\r\nMerci d’avoir créé un compte chez nous.\r\nClique sur le lien ci dessous pour l’activer et rejoins-nous vite :\r\nhttp://localhost:8100".WEBROOT."user/valideAccount/".$token;
    if(mail($mail, $subject, $message))
      return(1);
    else
      return (0);
  }

  function verifPass($pass) {
    if (preg_match('/(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*\W).{6,}$/', $pass)) {
      return (1);
    } else {
      return (0);
    }
  }

  function signin($p){
    if (!empty($p)) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    $model = $this->loadModel('user');
    if (isset($_POST['signin']) && $_POST['signin'] == "Sign In") {
      if (isset($_POST['username']) && isset($_POST['email']) && isset($_POST['birthday']) && isset($_POST['country']) && isset($_POST['password']) && isset($_POST['passverif'])) {
        $username = $_POST['username'];
        $mail = $_POST['email'];
        $birth = $_POST['birthday'];
        $country = $_POST['country'];
        $password = $_POST['password'];
        $passverif = $_POST['passverif'];
        $users = $this->getUsers();
        foreach ($users as $key =>$value) {
          if (strcmp($value['email'], $mail) === 0) {
            $this->classinfo = "alert";
            $this->message = "Un compte avec ce mail existe déjà !";
            $this->render('signin');
            exit();
          }
          if (strcmp($value['username'], $username) === 0) {
            $this->classinfo = "alert";
            $this->message = "Un compte avec ce nom d'utilisateur existe déjà !";
            $this->render('signin');
            exit();
          }
        }
        if (!preg_match('/^[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}$/', $mail)) {
          $this->classinfo = "alert";
          $this->message = "Ton email n'est pas valide.";
          $this->render('signin');
          exit();
        }
        if (strcmp($password, $passverif) === 0){
          $respass = $this->verifPass($password);
          if ($respass) {
            $pass = hash('whirlpool', $password);
            $token = bin2hex(mcrypt_create_iv(32, MCRYPT_DEV_URANDOM));
            if (isset($_POST['city'])){
              $city = $_POST['city'];
              $model->signin($username, $mail, $birth, $pass, $country, $city, $token);
            }else {
              $model->signin($username, $mail, $birth, $pass, $country, null, $token);
            }
            $send = $this->sendMailSign($token, $mail);
            if ($send) {
              $this->message = "Le mail de confirmation a bien été envoyé ! <br> Veuillez confirmer en cliquant sur le lien fournit dans le mail précédemment cité.";
              $this->render('signin');
              exit();
            }
          } else {
            $this->classinfo = "alert";
            $this->message = "Le mot de passe doit au minimum comporter un chiffre, une minuscule, une majuscule et un caractère spécial.";
          }
          $this->render('signin');
        } else {
          $this->classinfo = "alert";
          $this->message = "Les mots de passe ne sont pas les mêmes, Recommence.";
          $this->render('signin');
          exit();
        }
      }
    }
    $this->render('signin');
  }

  function valideAccount($token) {
    $model = $this->loadModel('user');
    $this->users = $this->getUsers();
    $id_valide = null;
    $find = 0;
    if (isset($token[0])) {
      $token = $token[0];
      foreach ($this->users as $key => $value) {
        if ($token == $value['token']) {
          $id_valide = $value['id_user'];
          $find = 1;
        }
      }
      if ($find) {
        $model->valideUser($id_valide);
        header("Location:".WEBROOT."user/login/valide");
      } else {
        header("Location:".WEBROOT."home/page404");
        exit();
      }
    } else {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
  }

  function login($param){
    $model = $this->loadModel('User');
    $log = null;
    if (isset($param[0])) {
      if ($param[0] == "valide") {
        $this->message = "Tu viens de valider ton compte. <br> Tu peux maintenant te connecter";
      } elseif ($param[0] == "editpass") {
        $this->message = "Ton mot de passe a bien été modifié.";
      } else {
        header("Location:".WEBROOT."home/page404");
        exit();
      }
    }
    if (isset($_POST['login']) && isset($_POST['identity']) && isset($_POST['password']))
    {
      $identity = $_POST['identity'];
      $pass = $_POST['password'];
      $log = $model->login($identity);
      if ($log['validate'] == 1) {
        if (strcmp(hash('whirlpool', $pass), $log['password']) === 0){
          $_SESSION['id'] = $log['id_user'];
          $_SESSION['username'] = $log['username'];
          header("Location:".WEBROOT."home/gallery");
        }
        else {
          $this->classinfo = "alert";
          $this->message = "Mauvais mot de passe.";
          $this->render('login');
        }
      } else {
        $this->classinfo = "alert";
        $this->message = "Tu dois valider ton compte d'abord avec le lien envoyé sur ta boîte mail.";
        $this->render('login');
      }
    }
    $this->render('login');
  }

  function logout($id){
    $_SESSION['id'] = null;
    $_SESSION['username'] = null;
    session_destroy();
    header("Location:".WEBROOT."home/index");
  }

  function forgot($p) {
    if (!empty($p)) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    $model = $this->loadModel('user');
    if (isset($_POST['forgot']) && isset($_POST['identity']) && $_POST['forgot'] == "Réinitialisation du mot de passe") {
      $user = $model->login($_POST['identity']);
      $to = $user['email'];
      $subject = "Mot de passe oublié";
      $message = "Bonjour ".$user['username'].",\r\nTu as le droit d'oublier ton mot de passe.\r\nAllez clique sur ce lien et tout sera réglé.\r\nhttp://localhost:8100".WEBROOT."user/forgotPass/".$user['token'];
      mail($to, $subject, $message);
      header("Location:".WEBROOT."home/index/forgotpass");
    }
    $this->render('forgot');
  }
  function forgotPass($token) {
    $model = $this->loadModel('user');
    $this->user = $this->findUserToken($token[0]);
    $this->token = $token[0];
    if (isset($token[1])) {
      $this->classinfo = "alert";
      if ($token[1] == "invalidepass") {
        $this->message = "Le mot de passe doit au minimum comporter un chiffre, une minuscule, une majuscule et un caractère spécial.";
      } elseif ($token[1] == "same") {
        $this->message = "Les mots de passe ne sont pas les mêmes, Recommence.";
      }
      else {
        header("Location:".WEBROOT."home/page404");
        exit();
      }
    }
    if (isset($_POST['newPass']) && isset($_POST['password']) && isset($_POST['passverif'])) {
      $password = $_POST['password'];
      $passverif = $_POST['passverif'];
      if (strcmp($password, $passverif) === 0){
        $respass = $this->verifPass($password);
        if ($respass) {
          $pass = hash('whirlpool', $password);
          $res = $model->updatePass($pass, $this->user['id_user']);
          header("Location:".WEBROOT."user/login/editpass");
        } else {
          header("Location:".WEBROOT."user/forgotPass/".$token[0]."/invalidepass");
          exit();
        }
    } else {
      header("Location:".WEBROOT."user/forgotPass/".$token[0]."/same");
      exit();
    }
    }
    $this->render('forgotPass');
  }

  function account($id) {
    $model = $this->loadModel('user');
    $this->user = $model->displayUser($id[0]);
    if (!$this->user) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    if ($this->user['id_user'] != $_SESSION['id']) {
      header("Location:".WEBROOT."home/page404");
      exit();
    }
    $this->imgs = $model->displayImgUser($id[0]);
    if (isset($id[1]) && !empty($id[1])) {
      $this->classinfo = "alert";
      if ($id[1] == "same") {
        $this->message = "Les mots de passe ne sont pas les mêmes, <br> Recommence.";
      } elseif ($id[1] == "old") {
        $this->message = "Ce n'est pas le bon ancien mot de passe. <br> Recommence";
      } elseif ($id[1] == "securepass") {
        $this->message = "Le mot de passe n'est pas assez sécurisé.<br> Recommence.";
      } elseif ($id[1] == "modifpass") {
        $this->classinfo = "";
        $this->message = "Ton mot de passe a bien été modifié.";
      } elseif ($id[1] == "mail") {
        $this->message = "Un compte avec ce mail existe déjà !";
      } elseif ($id[1] == "username") {
        $this->message = "Un compte avec ce nom d'utilisateur existe déjà !";
      } else {
        header("Location:".WEBROOT."home/page404");
        exit();
      }
    }
    $this->render('account');
  }

  function editUser($id) {
    $model = $this->loadModel('user');
    $user = $model->displayUser($id[0]);
    $users = $this->getUsers();
    if ($_POST['edit_user'] == "Editer") {
      if (isset($_POST['username']) && isset($_POST['mail']) && isset($_POST['birthdate']) && isset($_POST['country'])) {
        $username = $_POST['username'];
        $mail = $_POST['mail'];
        $birth = $_POST['birthdate'];
        $country = $_POST['country'];
        $notif = intval($_POST['notif']);
        foreach ($users as $key =>$value) {
          if (strcmp($value['email'], $mail) === 0 && $value['id_user'] != $id[0]) {
            header("Location:".WEBROOT."user/account/".$id[0]."/mail");
            exit();
          }
          if (strcmp($value['username'], $username) === 0 && $value['id_user'] != $id[0]) {
            header("Location:".WEBROOT."user/account/".$id[0]."/username");
            exit();
          }
        }
        if (!empty($_POST['city'])) {
          $city = $_POST['city'];
        } else {
          $city = null;
        }
        $model->updateInfo($id[0], $username, $mail, $birth, $country, $city,$notif);
        header("Location:".WEBROOT."user/account/".$id[0]."");
      }
    }
  }

  function editPass($id) {
    $model = $this->loadModel('user');
    if (isset($id[0])) {
      $user = $model->displayUser($id[0]);
    }
    if (isset($_POST) && $_POST['editPass'] == "Modifier le mot de passe") {
      if (isset($_POST['oldpass']) && isset($_POST['password']) && isset($_POST['passverif'])) {
        $oldpass = $_POST['oldpass'];
        $password = $_POST['password'];
        $passverif = $_POST['passverif'];
        if (strcmp($password, $passverif) === 0) {
          if (strcmp(hash('whirlpool', $oldpass), $user['password']) === 0){
            $respass = $this->verifPass($password);
            if ($respass) {
              $pass = hash('whirlpool', $password);
              $model->updatePass($pass, $id[0]);
              header("Location:".WEBROOT."user/account/".$id[0]."/modifpass");
            } else {
              header("Location:".WEBROOT."user/account/".$id[0]."/securepass");
              exit();
            }
          } else {
            header("Location:".WEBROOT."user/account/".$id[0]."/old");
            exit();
          }
        } else {
          header("Location:".WEBROOT."user/account/".$id[0]."/same");
          exit();
        }
      }
    }
  }
}
