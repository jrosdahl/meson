# Test https://github.com/mesonbuild/meson/issues/2096
# Note that removing 'shnodep' from link_with: makes the error go away because
# then it is added after the static library is added to the link command.
test('shared-static', executable('shstexe', 'shstmain.c', link_with : [shnodep, stshdep]))

# Static library that needs a symbol defined in an object file. This already
# works, but good to add a test case early.
stodep = static_library('stodep', 'libsto.c')
test('stodep', executable('stodep', 'stomain.c', 'stobuilt.c', link_with : stodep))

# Test that an internal static library (instdep_b) that is first encountered
# transitively through an installed static library (instdep_a, is_internal()=False,
# so include_internals=False on that path) is still added to the link command
# when it is also reachable through a different internal static library
# (instdep_c, include_internals=True). Without the visited-set fix this link
# fails with an undefined symbol error.
instdep_b = static_library('instdep_b', 'instdep_b.c')
instdep_a = static_library('instdep_a', 'instdep_a.c', link_with : instdep_b, install : true)
instdep_c = static_library('instdep_c', 'instdep_c.c', link_with : instdep_b)
test('installed-dep', executable('instdep', 'instdep_main.c', link_with : [instdep_a, instdep_c]))
