<main>
  <?php
  if (empty($_SESSION['id'])) {
    header("Location:".WEBROOT."home/index");
  } ?>
  <h1> - Montage photo avec webcam - </h1>
  <div class="montageCss">
    <article class="montageVideo">
      <div class="stage">
        <h2><span class="tiret">- </span>Choisis un cadre <span class="tiret"> -</span></h2>
        <div class="choiceStage">
          <?php foreach ($this->var as $key => $val ): ?>
            <input type="radio" name="stage" value="<?= $val['id_stage'] ?>">
            <img class="demo" src="<?= WEBROOT.$val['path'] ?>" alt="" onclick="currentDiv(<?= $val['id_stage'] ?>)">
          <?php endforeach; ?>
        </div>
      </div>
      <div class="camera">
        <div class="draw">
        <video></video><!--
        --><canvas id="draw"></canvas>
        <?php foreach ($this->var as $key => $val ): ?>
            <img class="slide_stage" src="../<?= $val['path'] ?>" alt="<?= $val['name_stage'] ?>" style="display:none;">
        <?php endforeach; ?>
        </div>
        <div class="buttonDraw">
          <button id="delete" class="btn_canvas picture" style="display:none;" name="btn_del" ><i class="fas fa-trash-alt"></i></button>
          <button id="record" class="btn_canvas picture" style="display:none;" name="btn_down" ><i class="far fa-save"></i></button>
          <button class="picture" id="startpic" style="display:none;"><i class="fas fa-camera-retro"></i></button>
        </div>
        <div id="title_img" style="display:none;">
          <label>Un titre pour la photo: </label>
          <input id="title" type="text" name="title_img" value="">
        </div>
        <canvas id="hide_stage"></canvas>
      </div>
    </article>
    <aside>
      <h2><span class="tiret">- </span>Tes Photos<span class="tiret"> -</span></h2>
      <div class="img_aside">
        <?php foreach ($this->tab as $key => $value):?>
        <div class="polaroid">
          <img src="<?= WEBROOT.$value['path'] ?>" alt="<?= $value['title'] ?>" style="width:100%">
          <div class="letter">
            <p><?= $value['title'] ?></p>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
    <div class="link">
      <a href="<?= WEBROOT ?>user/account/<?= $_SESSION['id'] ?>"><h2><span class="tiret">- </span>Toutes tes photos<span class="tiret"> -</span></h2></a>
    </div>
    </aside>
  </div>
  <div class="link">
    <a href="<?= WEBROOT ?>member/load"><h2><span class="tiret">- </span>Upload<span class="tiret"> -</span></h2></a>
  </div>
</main>
<script src="<?= WEBROOT ?>public/js/camera.js"></script>
