<?php
//echo json_decode($_SESSION['user']);

$user = isset($_SESSION['user']) ? $_SESSION['user'] : null;
?>



<p id="userInfo"></p><br>



<script>
    //pasar php->json a js
    let datos = <?php echo json_encode($user); ?>;

    document.getElementById("userInfo").innerHTML = `
            idUsuari: ${datos.idUsuari} <br>
            Nom: ${datos.nom} <br>
            Email: ${datos.email} <br>
            Contrasenya: ${datos.contrasenya} <br>
        `;
</script>