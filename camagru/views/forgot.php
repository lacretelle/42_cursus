<main>
  <h2> - Mot de passe oublié - </h2>
  <article class="">
    <form action="<?= WEBROOT.'User/forgot' ?>" method="post">
      <div class="">
        <label> Ton identifiant : </label><input type="text" name="identity" value="" placeholder="identifiant ou email" required>
      </div>
      <input type="submit" name="forgot" value="Réinitialisation du mot de passe" class="submit">
    </form>
  </article>
</main>
