<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Camagru</title>
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" crossorigin="anonymous">
    <link href="https://fonts.googleapis.com/css?family=Playfair+Display" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Catamaran" rel="stylesheet">
    <link rel="stylesheet" href="<?= WEBROOT ?>public/css/style.css" type="text/css">
  </head>
  <body>
    <header>
      <ul>
        <li><a class="active" href="<?= WEBROOT.'home/index' ?>"><i class="fas fa-home"></i> Home</a></li>
        <li><a href="<?= WEBROOT.'home/gallery' ?>"><i class="far fa-image"></i> Gallery</a></li>
        <?php if (empty($_SESSION['id'])): ?>
        <li><a href="<?= WEBROOT.'user/login' ?>"><i class="fas fa-power-off"></i> Log In</a></li>
        <li><a href="<?= WEBROOT.'user/signin' ?>"><i class="fas fa-laptop-medical"></i> Sign In</a></li>
      <?php else : ?>
        <li><a href="<?= WEBROOT.'member/home' ?>"> <i class="fas fa-camera-retro"></i> Montage photo</a></li>
        <li><a href="<?= WEBROOT.'user/account/'.$_SESSION['id'] ?>"> <i class="fas fa-user"></i> Account</a></li>
        <li><a href="<?= WEBROOT.'user/logout/'.$_SESSION['id'] ?>"><i class="fas fa-sign-out-alt"></i> Log Out</a></li>
      <?php endif; ?>
      </ul>
    </header>
    <div id="message" style="display:none;">
    </div>
    <?php if (isset($this->message) && !empty($this->message)):?>
      <?php if (isset($this->classinfo) && $this->classinfo == "alert"): ?>
      <div id="note" style="display:flex;" class="alert">
      <?php else: ?>
        <div id="note" style="display:flex;" class="success">
        <?php endif; ?>
        <p><?= $this->message ?></p>
      </div>
    <?php else: ?>
    <div id="note" style="display:none;">
    </div>
  <?php endif; ?>
    <?php
    echo $content;
    ?>
  </body>

  <footer>
    <?php if (empty($_SESSION['id'])): ?>
    <div class="contentFoot">
      <a href="<?= WEBROOT.'user/login' ?>">Login</a>
    </div>
    <div class="contentFoot">
      <a href="<?= WEBROOT.'user/signin' ?>">Sign in</a>
    </div>
  <?php else: ?>
    <div class="contentFoot">
      <a href="<?= WEBROOT.'user/account/'.$_SESSION['id'] ?>">Account</a>
    </div>
    <div class="contentFoot">
      <a href="<?= WEBROOT.'user/logout/'.$_SESSION['id'] ?>">Log out</a>
    </div>
    <?php endif; ?>
  </footer>
</html>
