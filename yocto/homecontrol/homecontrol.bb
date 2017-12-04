SUMMARY = "Home Control app"
HOMEPAGE = "http://www.danielsan.com.br"
LICENSE = "GPLv3"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-3.0;md5=c79ff39f19dfec6d293b95dea7b07891"

DEPENDS += "qtdeclarative"

PR = "r1"

SRCREV = "3c82891daaabd9cfdb3099a7762802bb2ed7c453"
SRC_URI = "git://github.com/danielsanfr/home-control.git"

S = "${WORKDIR}/git"

require recipes-qt/qt5/qt5.inc

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/${PN} ${D}${bindir}
}

FILES_${PN} = "${bindir}"

RDEPENDS_${PN} = "qtdeclarative-qmlplugins"
