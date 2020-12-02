<main>
  <h2> - Connecte Toi - </h2>
  <article class="">
    <form action="<?= WEBROOT.'User/login' ?>" method="post">
      <div class="">
        <label> Ton identifiant : </label><input type="text" name="identity" value="" placeholder="identifiant ou email" required>
      </div>
      <div class="">
        <label> Ton mot de passe : </label><input type="password" name="password" value="" required>
      </div>
      <input type="submit" name="login" value="Login" class="submit">
    </form>
    <div class="">
      <a class="submit" href="<?= WEBROOT.'user/forgot' ?>">Mot de passe oublié</a>
    </div>
  </article>
</main>
