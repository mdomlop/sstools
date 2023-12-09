#define PKGNAME         "sskit"
#define PKGDESCRIPTION  "KISS tools for make snapshots in a Btrfs filesystem."
#define VERSION         "0.7b"
#define URL             "https://github.com/mdomlop/sskit"
#define LICENSE         "GPLv3+"
#define AUTHOR          "Manuel Domínguez López"
#define NICK            "mdomlop"
#define MAIL            "zqbzybc@tznvy.pbz"

void version (void)
{
	printf ("%s Version: %s\n", PROGRAM, VERSION);
}