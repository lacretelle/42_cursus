<main>
  <?php
  if (empty($_SESSION['id'])) {
    header("Location:".WEBROOT."home/index");
  } ?>
    <h1>Ton compte</h1>
    <div class="stage">
      <h2><span class="tiret">- </span>Tes informations personnelles<span class="tiret"> -</span></h2>
      <div class="infoUser">
        <button type="button" name="displayInfo" onclick="displayInfo()"><i class="fas fa-user-circle"></i></button>
      </div>
    </div>
    <article class="account" style="display:none;">
      <div class="container">
        <h2><span class="tiret">- </span>Infos personnelles<span class="tiret"> -</span></h2>
        <form action="<?= WEBROOT.'user/editUser/'.$this->user['id_user'] ?>" method="post">
          <div>
            <label>Nom d'utilisateur :</label>
            <input type="text" name="username" value="<?= $this->user['username'] ?>">
          </div>
          <div class="">
            <label>Email :</label>
            <input type="text" name="mail" value="<?= $this->user['email'] ?>">
          </div>
          <div class="">
            <label>Date de naissance :</label>
            <input type="date" name="birthdate" value="<?= $this->user['birthday'] ?>" max="2001-12-31">
          </div>
          <div class="">
            <label>Pays :</label>
            <input type="text" name="country" value="<?= $this->user['country'] ?>">
          </div>
          <div class="">
            <label>Ville :</label>
            <input type="text" name="city" value="<?= $this->user['city'] ?>">
          </div>
          <div class="">
            <label>Recevoir les notifications:</label>
            <label class="switch">
              <?php if ($this->user['notification'] == 1): ?>
              <input type="checkbox" checked>
            <?php else: ?>
              <input type="checkbox">
            <?php endif ?>
              <span class="slider round"></span>
            </label>
          </div>
          <input type="hidden" name="notif" value="<?= $this->user['notification'] ?>">
          <input type="submit" name="edit_user" value="Editer" class="submit">
        </form>
      </div>
      <div class="up">
        <button type="button" name="undisplayInfo" onclick="hideInfo()"><i class="fas fa-angle-double-up"></i></button>
      </div>
      </article>
      <br>
      <article class="account" style="display:none;">
      <div class="container">
        <h2><span class="tiret">- </span>Changement de mot de passe<span class="tiret"> -</span></h2>
        <form action="<?= WEBROOT.'user/editPass/'.$this->user['id_user'] ?>" method="post">
          <div class="">
            <label>Mot de passe actuel :</label>
            <input type="password" name="oldpass" value="">
          </div>
          <div class="">
            <label>Nouveau mot de passe :</label>
            <input type="password" name="password" value=""  minlength="6">
          </div>
          <div class="">
            <label>Confirmer mot de passe :</label>
            <input type="password" name="passverif" value="">
          </div>
          <input type="submit" name="editPass" value="Modifier le mot de passe" class="submit">
        </form>
      </div>
      <div class="up">
        <button type="button" name="undisplayInfo" onclick="hideInfo()"><i class="fas fa-angle-double-up"></i></button>
      </div>
    </article>
    <br>
    <article>
      <h2><span class="tiret">- </span>Tes Montages<span class="tiret"> -</span></h2>
      <?php foreach ($this->imgs as $key => $value): ?>
        <div class="polaroid">
          <img src="<?= WEBROOT.$value['path']?>" alt="<?= $value['title']?>" style="width:100%">
          <div class="letter">
            <p><?= $value['title']?></p>
            <a href="<?= WEBROOT?>member/delete_img/<?= $value['id_img'] ?>" style="color:red;"><i class="fas fa-times"></i></a>
          </div>
        </div>
      <?php endforeach; ?>
      <div>
        <a href="<?= WEBROOT."member/delete_all/".$_SESSION['id']?>" style="color:red;"><i class="fas fa-trash-alt"></i> Tout supprimer</a>
      </div>
    </article>
</main>
<script type="text/javascript" src="<?= WEBROOT ?>public/js/account.js"></script>
