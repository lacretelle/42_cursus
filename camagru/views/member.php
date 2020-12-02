<main>
  <?php
  if (empty($_SESSION['id'])) {
    header("Location:".WEBROOT."home/index");
  } ?>
  <h1> - Montage photo - </h1>
  <div class="stage">
    <h2><span class="tiret">- </span>Choisissez<span class="tiret"> -</span></h2>
    <div class="camLoad">
      <a href="<?= WEBROOT ?>member/webcam" class="webcam">
        <i class="fas fa-camera-retro"></i>
      </a>
      <a href="<?= WEBROOT ?>member/load" class="load">
        <i class="fas fa-upload"></i>
      </a>
    </div>
  </div>
  <div class="imgMember">
    <img src="<?= WEBROOT ?>public/img/montage/pikachu.png" alt="pikachu">
  </div>
</main>
