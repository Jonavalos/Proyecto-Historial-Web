#include "Control.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "Pestana.h"
#include "SitioWeb.h"

// Tests que simulan las funciones principales de Pestana 
// como busqueda, asignar, buscar coincidencia. Son las operaciones principales del programa
//  NO se puede usar DELETE en los TEST, al Visual no le termina de agradar la idea
//  Para usar los tests, descomentar el codigo indicado en main
TEST(PestanaTest, FiltroCoincide) {
    Pestana pestana(1);
    std::vector<std::string>* tags = new std::vector<std::string>();
    // crear sitios web de ejemplo
    SitioWeb* sitio1 = new SitioWeb("Google", "google.com", "https://www.google.com", tags, false);
    SitioWeb* sitio2 = new SitioWeb("YouTube", "youtube.com", "https://www.youtube.com", tags, false);
    SitioWeb* sitio3 = new SitioWeb("Facebook", "facebook.com", "https://www.facebook.com", tags, false);
    //asignarlos como disponibles en la pestana
    std::vector<SitioWeb*> sitiosDisponibles;
    sitiosDisponibles.push_back(sitio1);
    sitiosDisponibles.push_back(sitio2);
    sitiosDisponibles.push_back(sitio3);
    pestana.setSitiosDisponibles(sitiosDisponibles);
    //asignarlos a pestana actual, o sea, "buscarlos"
    pestana.asignarActual("Google");
    pestana.asignarActual("YouTube");
    pestana.asignarActual("Facebook");

    //buscar ou
    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("ou");

    // comprobar que se ha devuelto Youtube
    ASSERT_EQ(resultado.size(), 1);
    EXPECT_EQ(resultado[0]->getTitulo(), "YouTube");

}

TEST(PestanaTest, FiltroNoCoincide) {
    Pestana pestana(1);
    std::vector<std::string>* tags = new std::vector<std::string>();
   
    SitioWeb* sitio1 = new SitioWeb("Google", "google.com", "https://www.google.com", tags, false);
    SitioWeb* sitio2 = new SitioWeb("YouTube", "youtube.com", "https://www.youtube.com", tags, false);
    SitioWeb* sitio3 = new SitioWeb("Facebook", "facebook.com", "https://www.facebook.com", tags, false);

    std::vector<SitioWeb*> sitiosDisponibles;
    sitiosDisponibles.push_back(sitio1);
    sitiosDisponibles.push_back(sitio2);
    sitiosDisponibles.push_back(sitio3);
    pestana.setSitiosDisponibles(sitiosDisponibles);

    pestana.asignarActual("Google");
    pestana.asignarActual("YouTube");
    pestana.asignarActual("Facebook");

    //buscar itte
    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("itte");

    // comprobar que se NO se ha devuelto Twitter (falla)
    ASSERT_EQ(resultado.size(), 1);
    EXPECT_EQ(resultado[0]->getTitulo(), "Twitter");

}

TEST(PestanaTest, HistorialVacio) {
    Pestana pestana(1);
    std::vector<std::string>* tags = new std::vector<std::string>();

    SitioWeb* sitio1 = new SitioWeb("Google", "google.com", "https://www.google.com", tags, false);
    SitioWeb* sitio2 = new SitioWeb("YouTube", "youtube.com", "https://www.youtube.com", tags, false);
    SitioWeb* sitio3 = new SitioWeb("Facebook", "facebook.com", "https://www.facebook.com", tags, false);

    std::vector<SitioWeb*> sitiosDisponibles;
    sitiosDisponibles.push_back(sitio1);
    sitiosDisponibles.push_back(sitio2);
    sitiosDisponibles.push_back(sitio3);
    pestana.setSitiosDisponibles(sitiosDisponibles);

    //no se agregan al historial
    /*pestana.asignarActual("Google");
    pestana.asignarActual("YouTube");
    pestana.asignarActual("Facebook");*/

    //buscar itte
    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("ou");

    // comprobar que se NO se ha devuelto YouTube (FALLA)
    ASSERT_EQ(resultado.size(), 1);
    EXPECT_EQ(resultado[0]->getTitulo(), "YouTube");

}

TEST(PestanaTest, sinFiltro) {
    Pestana pestana(1);
    std::vector<std::string>* tags = new std::vector<std::string>();
    
    SitioWeb* sitio1 = new SitioWeb("Google", "google.com", "https://www.google.com", tags, false);
    SitioWeb* sitio2 = new SitioWeb("YouTube", "youtube.com", "https://www.youtube.com", tags, false);
    SitioWeb* sitio3 = new SitioWeb("Facebook", "facebook.com", "https://www.facebook.com", tags, false);

    std::vector<SitioWeb*> sitiosDisponibles;
    sitiosDisponibles.push_back(sitio1);
    sitiosDisponibles.push_back(sitio2);
    sitiosDisponibles.push_back(sitio3);
    pestana.setSitiosDisponibles(sitiosDisponibles);

    pestana.asignarActual("Google");
    pestana.asignarActual("YouTube");

    //buscar ou
    std::vector<SitioWeb*> resultado = pestana.busquedaEnHistorial("");

    // comprobar que se ingresaron los 2
    ASSERT_EQ(resultado.size(), 2);

}

// este programa incluye las bibliotecas: iostream, sstream, string, conio.h, algorithm, windows.h, 
// fstream, vector, chrono, gtest/gtest.h
// esa ultima usa microsoft google test descargado desde visual
int main(int argc, char** argv) {
    
    //Usar para tests
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();

    //Usar para el programa normal
    Control::getInstance()->navegar();


   //Sitios usados como ejemplo en este programa

   //SitioWeb* sitio1 = new SitioWeb("Google", "google.com", "https://www.google.com", tags, false);
   //SitioWeb* sitio2 = new SitioWeb("YouTube", "youtube.com", "https://www.youtube.com", tags, false);
   //SitioWeb* sitio3 = new SitioWeb("Facebook", "facebook.com", "https://www.facebook.com", tags, false);
   //SitioWeb* sitio4 = new SitioWeb("Amazon", "amazon.com", "https://www.amazon.com", tags, false);
   //SitioWeb* sitio5 = new SitioWeb("Wikipedia", "wikipedia.org", "https://www.wikipedia.org", tags, false);
   //SitioWeb* sitio6 = new SitioWeb("Twitter", "twitter.com", "https://www.twitter.com", tags, false);
   //SitioWeb* sitio7 = new SitioWeb("Instagram", "instagram.com", "https://www.instagram.com", tags, false);
   //SitioWeb* sitio8 = new SitioWeb("LinkedIn", "linkedin.com", "https://www.linkedin.com", tags, false);
   //SitioWeb* sitio9 = new SitioWeb("Netflix", "netflix.com", "https://www.netflix.com", tags, false);
   //SitioWeb* sitio10 = new SitioWeb("Reddit", "reddit.com", "https://www.reddit.com", tags, false);

   //SitioWeb* sitio11 = new SitioWeb("Pinterest", "pinterest.com", "https://www.pinterest.com", tags, false);
   //SitioWeb* sitio12 = new SitioWeb("Quora", "quora.com", "https://www.quora.com", tags, false);
   //SitioWeb* sitio13 = new SitioWeb("Dropbox", "dropbox.com", "https://www.dropbox.com", tags, false);
   //SitioWeb* sitio14 = new SitioWeb("GitHub", "github.com", "https://www.github.com", tags, false);
   //SitioWeb* sitio15 = new SitioWeb("Slack", "slack.com", "https://www.slack.com", tags, false);
   //SitioWeb* sitio16 = new SitioWeb("Zoom", "zoom.us", "https://www.zoom.us", tags, false);
   //SitioWeb* sitio17 = new SitioWeb("Spotify", "spotify.com", "https://www.spotify.com", tags, false);
   //SitioWeb* sitio18 = new SitioWeb("Twitch", "twitch.tv", "https://www.twitch.tv", tags, false);
   //SitioWeb* sitio19 = new SitioWeb("Microsoft", "microsoft.com", "https://www.microsoft.com", tags, false);
   //SitioWeb* sitio20 = new SitioWeb("Apple", "apple.com", "https://www.apple.com", tags, false);

   //SitioWeb* sitio21 = new SitioWeb("Adobe", "adobe.com", "https://www.adobe.com", tags, false);
   //SitioWeb* sitio22 = new SitioWeb("Stack Overflow", "stackoverflow.com", "https://www.stackoverflow.com", tags, false);
   //SitioWeb* sitio23 = new SitioWeb("Coursera", "coursera.org", "https://www.coursera.org", tags, false);
   //SitioWeb* sitio24 = new SitioWeb("Udemy", "udemy.com", "https://www.udemy.com", tags, false);
   //SitioWeb* sitio25 = new SitioWeb("Khan Academy", "khanacademy.org", "https://www.khanacademy.org", tags, false);

    return 0;
}
