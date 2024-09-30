//#include <gtest/gtest.h>
//#include <vector>
//#include <string>
//#include "Pestana.h"
//#include "SitioWeb.h"  // Incluye las clases necesarias
//
//// Simulaci�n simple de la funci�n "contiene"
//bool contiene(const std::string& filtro, const std::string& titulo) {
//    return titulo.find(filtro) != std::string::npos;
//}
//std::vector<std::string>* tags = new std::vector<std::string>();
//// Test para buscar en historial con filtro coincidente
//TEST(PestanaTest, FiltroCoincide) {
//    Pestana pestana(1);
//
//    // Creamos sitios web de ejemplo
//    SitioWeb sitio1("Google", "google.com", "https://www.google.com", tags, false);
//    SitioWeb sitio2("Stack Overflow", "stackoverflow.com", "https://www.stackoverflow.com", tags, false);
//    SitioWeb sitio3("GitHub", "github.com", "https://www.github.com", tags, false);
//
//    // Los a�adimos al historial de Pestana
//    pestana.getHistorialSitios().push_back(&sitio1);
//    pestana.getHistorialSitios().push_back(&sitio2);
//    pestana.getHistorialSitios().push_back(&sitio3);
//
//    // Realizamos la b�squeda con el filtro "Stack"
//    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("Stack");
//
//    // Comprobamos que se ha devuelto StackOverflow
//    ASSERT_EQ(resultado.size(), 1);
//    EXPECT_EQ(resultado[0]->getTitulo(), "StackOverflow");
//}

//// Test para buscar en historial sin coincidencias
//TEST(PestanaTest, FiltroNoCoincide) {
//    Pestana pestana;
//
//    // Creamos sitios web de ejemplo
//    SitioWeb sitio1("Google", "https://google.com");
//    SitioWeb sitio2("StackOverflow", "https://stackoverflow.com");
//
//    // Los a�adimos al historial de Pestana
//    pestana.historialSitios.push_back(&sitio1);
//    pestana.historialSitios.push_back(&sitio2);
//
//    // Realizamos la b�squeda con un filtro que no existe
//    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("Yahoo");
//
//    // Comprobamos que no hay resultados
//    EXPECT_EQ(resultado.size(), 0);
//}
//
//// Test con historial vac�o
//TEST(PestanaTest, HistorialVacio) {
//    Pestana pestana;
//
//    // Realizamos la b�squeda en un historial vac�o
//    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("Google");
//
//    // Comprobamos que no hay resultados
//    EXPECT_EQ(resultado.size(), 0);
//}
//
//// Test con filtro vac�o
//TEST(PestanaTest, FiltroVacio) {
//    Pestana pestana;
//
//    // Creamos sitios web de ejemplo
//    SitioWeb sitio1("Google", "https://google.com");
//    SitioWeb sitio2("StackOverflow", "https://stackoverflow.com");
//
//    // Los a�adimos al historial de Pestana
//    pestana.historialSitios.push_back(&sitio1);
//    pestana.historialSitios.push_back(&sitio2);
//
//    // Realizamos la b�squeda con un filtro vac�o
//    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("");
//
//    // Comprobamos que devuelve todos los sitios
//    EXPECT_EQ(resultado.size(), 2);
//}