#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <mysql/mysql.h>
#include <openssl/sha.h>

// Funció per connectar-se a MySQL
MYSQL* connectDB() {
    MYSQL* conn = mysql_init(nullptr);
    if (!conn) {
        std::cerr << "Error en inicialitzar MySQL\n";
        return nullptr;
    }

    conn = mysql_real_connect(conn, "localhost", "root", "password", "ticketing_db", 3306, nullptr, 0);
    if (!conn) {
        std::cerr << "Error de connexió: " << mysql_error(conn) << "\n";
    }
    return conn;
}

// Funció per encriptar la contrasenya amb SHA-256
std::string hashContrasenya(const std::string& contrasenya) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(contrasenya.c_str()), contrasenya.size(), hash);

    std::string hashedPassword;
    for (unsigned char i : hash) {
        char buffer[3];
        sprintf(buffer, "%02x", i);
        hashedPassword += buffer;
    }
    return hashedPassword;
}

// Funció per validar l'email
bool esEmailValid(const std::string& email) {
    const std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailRegex);
}

// Funció per registrar un usuari
void user_register() {
    std::string nomUsuari, email, contrasenya, rol;
    std::vector<std::string> itemsSeleccionats;

    // Demanar dades a l'usuari
    std::cout << "Introdueix el teu nom d'usuari: ";
    std::cin >> nomUsuari;
    std::cout << "Introdueix el teu email: ";
    std::cin >> email;
    std::cout << "Introdueix la teva contrasenya: ";
    std::cin >> contrasenya;

    // Validacions bàsiques
    if (nomUsuari.empty() || email.empty() || contrasenya.empty()) {
        std::cerr << "Error: Tots els camps són obligatoris.\n";
        return;
    }
    if (!esEmailValid(email)) {
        std::cerr << "Error: L'email no té un format vàlid.\n";
        return;
    }
    if (contrasenya.length() < 6) {
        std::cerr << "Error: La contrasenya ha de tenir almenys 6 caràcters.\n";
        return;
    }

    // Selecció del rol
    std::cout << "Selecciona el teu rol (Client, Organitzador, Administrador): ";
    std::cin >> rol;
    if (rol != "Client" && rol != "Organitzador" && rol != "Administrador") {
        std::cerr << "Error: Rol invàlid. Has d'introduir Client, Organitzador o Administrador.\n";
        return;
    }

    // Selecció d'ítems personalitzats
    int numItems;
    std::cout << "Quants ítems vols afegir al teu perfil?: ";
    std::cin >> numItems;

    for (int i = 0; i < numItems; i++) {
        std::string item;
        std::cout << "Introdueix l’ítem " << (i + 1) << ": ";
        std::cin >> item;
        itemsSeleccionats.push_back(item);
    }

    // Encriptar la contrasenya abans de guardar-la
    std::string hashedPassword = hashContrasenya(contrasenya);

    // Connexió a la base de dades
    MYSQL* conn = connectDB();
    if (!conn) return;

    // Preparar la consulta SQL per inserir l’usuari
    std::string query = "INSERT INTO usuaris (nom_usuari, email, contrasenya, rol) VALUES ('"
                        + nomUsuari + "', '" + email + "', '" + hashedPassword + "', '" + rol + "')";

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Error en registrar usuari: " << mysql_error(conn) << "\n";
        mysql_close(conn);
        return;
    }

    // Obtenir l'ID de l'usuari acabat de crear
    int user_id = mysql_insert_id(conn);

    // Inserir els ítems seleccionats a la base de dades
    for (const auto& item : itemsSeleccionats) {
        std::string itemQuery = "INSERT INTO usuaris_items (id_usuari, item) VALUES (" 
                                + std::to_string(user_id) + ", '" + item + "')";
        if (mysql_query(conn, itemQuery.c_str())) {
            std::cerr << "Error en inserir ítem: " << mysql_error(conn) << "\n";
        }
    }

    std::cout << "Usuari registrat correctament!\n";
    mysql_close(conn);
}
