PACKAGES =+ "${PN}-tools"

INSANE_SKIP_${PN}-tools = "ldflags"

FILES_${PN}-tools = "${bindir}/swupdate-client \
                    ${bindir}/swupdate-progress \
                    ${bindir}/swupdate-hawkbitcfg \
                    ${bindir}/swupdate-sendtohawkbit \
                    ${bindir}/swupdate-sysrestart"

do_compile() {
  unset LDFLAGS

  oe_runmake
  cp swupdate_unstripped swupdate
}

do_install_append () {

  install -m 0755 tools/swupdate-client_unstripped ${D}${bindir}/swupdate-client
  install -m 0755 tools/swupdate-progress_unstripped ${D}${bindir}/swupdate-progress
  install -m 0755 tools/swupdate-hawkbitcfg_unstripped ${D}${bindir}/swupdate-hawkbitcfg
  install -m 0755 tools/swupdate-sendtohawkbit_unstripped ${D}${bindir}/swupdate-sendtohawkbit
  install -m 0755 tools/swupdate-sysrestart_unstripped ${D}${bindir}/swupdate-sysrestart
}
