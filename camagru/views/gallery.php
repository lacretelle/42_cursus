<main>
  <h1>Gallerie Photos </h1>
  <article>
    <?php if (!isset($_SESSION['id'])) : ?>
      <div class="advise">
        <p>Vous devez vous connecter <i class="fas fa-power-off"></i><br> pour liker <i class="far fa-heart"></i> <br>et/ou commenter <i class="fas fa-comment-medical"></i></p>
      </div>
    <?php endif; ?>
    <?php foreach ($this->var as $key => $value): ?>
      <div class="container">
        <h2><span class="tiret">- </span><?= $value['title']?><span class="tiret"> -</span></h2>
        <img src="<?= WEBROOT.$value['path']?>" alt="">
        <?php if (!empty($_SESSION['id'])): ?>
          <div class="posts">
            <?php $liked = 0;
            foreach ($this->likes as $k => $val) {
              if ($val['id_img'] == $value['id_img']) {
                $liked = 1;
              }
            } ?>
            <?php if ($liked == 0):?>
            <button type="button" name="count_like" id="<?= $value['id_img']?>" onclick="like(<?= $value['id_img']?>)" style="color:rgb(212,175,55);">
            <?php else :?>
              <button type="button" name="count_like" id="<?= $value['id_img']?>" onclick="like(<?= $value['id_img']?>)" style="color:red;">
            <?php endif; ?>
            <i class="far fa-heart" id="heart<?= $value['id_img']?>">
              <?php foreach ($this->nbLike as $item => $i) {
              if ($i['id_img'] == $value['id_img']) {
                echo $i['nbLike'];
              }
              } ?>
            </i></button>
            <button type="button" name="com" onclick="displayPost(<?= $value['id_img']?>)"><i class="far fa-comments" id="comments<?= $value['id_img']?>">
              <?php foreach ($this->nbPost as $post => $p) {
              if ($p['id_img'] == $value['id_img']) {
                echo $p['nbPost'];
              }
              } ?>
            </i></button>
            <button type="button" name="com_add" onclick="post(<?= $value['id_img']?>)"><i class="fas fa-comment-medical"></i></button>
          </div>
          <div class="comments" id="post_<?= $value['id_img']?>" style="display:none;">
            <h3>Ecris: </h3>
            <textarea id="com_<?= $value['id_img']?>" name="name" rows="8" cols="80"></textarea>
            <button type="button" class="submit" name="addpost" onclick="addPost(<?= $value['id_img']?>)">Ajouter</button>
          </div>
        <?php else: ?>
          <div class="posts">
            <button type="button" name="count_like"><i class="far fa-heart">
              <?php foreach ($this->nbLike as $item => $i) {
              if ($i['id_img'] == $value['id_img']) {
                echo $i['nbLike'];
              }
              } ?>
            </i></button>
            <button type="button" name="com" onclick="displayPost(<?= $value['id_img']?>)"><i class="far fa-comments">
              <?php foreach ($this->nbPost as $post => $p) {
              if ($p['id_img'] == $value['id_img']) {
                echo $p['nbPost'];
              }
              } ?>
            </i></button>
          </div>
      <?php endif; ?>
      <div class="displayCom" id="displayCom_<?= $value['id_img']?>" style="display:none;">
        <h3>Commentaires: </h3>
        <?php foreach ($this->allPost as $i => $j):?>
          <?php if ($j['id_img'] == $value['id_img']): ?>
            <div class="com_p">
              <p><?= ucfirst($j['username']) ?> a écrit: </p>
              <p><?= htmlspecialchars($j['comment']); ?></p>
            </div>
          <?php endif; ?>
      <?php endforeach; ?>
      </div>
    </div>
    <hr>
    <?php endforeach; ?>
  </article>
  <div class="pagination">
    <a class="a_fas" href="<?= WEBROOT.'home/gallery/1'?>"><i class="fas fa-angle-double-left"></i></a>
    <?php $i = 0;
    while ($i < $this->page_max) {
      if ($i + 1 == $this->page):
      ?>
      <a class="active" href="<?= WEBROOT.'home/gallery/'.($i + 1)?>"><?= $i + 1 ?></a>
      <?php
    else: ?>
    <a href="<?= WEBROOT.'home/gallery/'.($i + 1)?>"><?= $i + 1 ?></a>
    <?php
    endif;
      $i++;
    }
    if ($this->page_max > 1) {
      ?>
      <a class="a_fas" href="<?= WEBROOT.'home/gallery/'.$this->page_max?>"><i class="fas fa-angle-double-right"></i></a>
      <?php
    }?>
  </div>
</main>
<script type="text/javascript" src="<?= WEBROOT ?>public/js/gallery.js"></script>
