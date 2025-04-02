<?php
require_once __DIR__ . "/../app/controllers/UserController.php";

$request = $_SERVER['REQUEST_URI'];
$method = $_SERVER["REQUEST_METHOD"];

$controller = new UserController();
$view = null;

// Rutas de vistas
if ($request == "/" && $method == "GET") {
    $view = __DIR__ . "/../app/views/home.php"; 
} elseif ($request == "/login" && $method == "GET") {
    $view = __DIR__ . "/../app/views/users/login.php";
} elseif ($request == "/dashboard" && $method == "GET") {
    $view = __DIR__ . "/../app/views/users/dashboard.php";
} 

// Rutas de controladores (no necesitan `base.php`)
elseif ($request == "/login_input" && $method == "POST") {
    $controller->login();
    exit();
} elseif ($request == "/logout") {
    $controller->logout();
    exit();
}

// Si `$view` sigue siendo null, mostrar error 404
if ($view === null || !file_exists($view)) {
    http_response_code(404);
    $view = __DIR__ . "/../app/views/404.php";
}
//forzamos la vista plantilla siempre
include __DIR__ . "/../app/views/base.php";

?>