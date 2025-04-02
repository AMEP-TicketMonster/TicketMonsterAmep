<?php
 //echo json_decode($_SESSION['user']);
$datos_json = isset($_SESSION['user']) ? $_SESSION['user'] : '{}'; // Obtener JSON de la sesión
?>

    <p id="userInfo"></p>

    <script>
        //pasar php->json a js
        let datos = <?php echo $datos_json; ?>;

        document.getElementById("userInfo").innerHTML = `
            idUsuari: ${datos.idUsuari} <br>
            Nom: ${datos.nom} <br>
            Email: ${datos.email} <br>
            Contrasenya: ${datos.contrasenya} <br>
        `;

    </script>

