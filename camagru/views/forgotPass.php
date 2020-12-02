<main>
  <h2>- Change ton mot de passe -</h2>
  <article>
    <form class="" action="<?= WEBROOT.'user/forgotPass/'.$this->token ?>" method="post">
      <div class="">
        <label> Ton nouveau mot de passe : *</label><input type="password" name="password" value="" required>
      </div>
      <div class="">
        <label> Confirme le nouveau mot de passe : *</label><input type="password" name="passverif" value="" required>
      </div>
      <input type="submit" name="newPass" value="Valider" class="submit">
    </form>
  </article>
</main>
