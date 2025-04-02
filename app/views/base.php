<!DOCTYPE html>
<html lang="es">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TicketMonster</title>

    <link rel="stylesheet" href="/public/bootstrap-5.3.3/css/bootstrap.min.css">
    <script src="/public/bootstrap-5.3.3/js/bootstrap.bundle.min.js"></script>
</head>

<body>
    <!-- Navbar -->
     <?php $logged = $_SESSION['session_status']?>
     
    <nav class="navbar navbar-dark bg-dark">
        <div class="container-fluid">
            <a class="navbar-brand" href="/">TicketMonster</a>
            <a href="/login" class="btn btn-outline-light ms-auto">Login</a>
        </div>
    </nav>
    <div class="container mt-4">
        <?php //más adelante me interasará hacer componentes //include __DIR__ . "/partials/navbar.php"; ?>

        <!-- Contenido dinámico -->
        <main>
            <?php
            if (isset($view)) {
                include $view;
            } else {
                echo "<p>Error: No se encontró la vista.</p>";
            }
            ?>
        </main>

        <!-- Footer -->
        <?php //  include __DIR__ . "/partials/footer.php"; ?>
        
    </div>
</body>

</html>