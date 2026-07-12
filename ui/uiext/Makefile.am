## Process this file with automake to produce Makefile.in
## Copyright (c) 2001-2017 Philip Kendall, Sergio Baldoví

## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; if not, write to the Free Software Foundation, Inc.,
## 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
##
## Author contact information:
##
## E-mail: philip-fuse@shadowmagic.org.uk
##         ruslan.gr@gmail.com

if UI_UIEXT

fuse_SOURCES += $(ui_uiext_files)

BUILT_SOURCES += $(ui_uiext_built)

endif

CLEANFILES += $(ui_uiext_built)

ui_uiext_files = \
		ui/uiext/uiext_ui.c \
		ui/uiext/keysyms.c

# ui_uiext_built = \
#                 ui/uiext/options.c

# EXTRA_DIST += \
#               ui/uiext/options.pl \
#               ui/uiext/options-header.pl

# ui/uiext/options.c: $(srcdir)/perl/cpp-perl.pl config.h $(srcdir)/ui/uiext/options.pl $(srcdir)/ui/options.dat $(srcdir)/perl/Fuse.pm $(srcdir)/perl/Fuse/Dialog.pm
# 	@$(MKDIR_P) ui/uiext
# 	$(AM_V_GEN)$(PERL) $(srcdir)/perl/cpp-perl.pl config.h $(srcdir)/ui/options.dat | $(PERL) -I$(srcdir)/perl $(srcdir)/ui/uiext/options.pl - > $@.tmp && mv $@.tmp $@


# ui_uiext_built = ui/uiext/keysyms.c

# ui/uiext/keysyms.c: $(srcdir)/keysyms.pl $(srcdir)/keysyms.dat
# 	@$(MKDIR_P) ui/uiext
# 	$(AM_V_GEN)$(PERL) -I$(srcdir)/perl $(srcdir)/keysyms.pl uiext $(srcdir)/keysyms.dat > $@.tmp && mv $@.tmp $@


if BUILD_PYEXT
# generate fuzx/objfiles.txt with $(fuse_OBJECTS)


# dump fuse_OBJECTS, fuse_LDADD, fuse_DEPENDENCIES
export-link-config: $(fuse_OBJECTS)
	@echo "[build]" > $(export_var_file)
	@echo "object_files=$(fuse_OBJECTS)" >> $(export_var_file)
	@echo "ldadd=$(fuse_LDADD)" >> $(export_var_file)



# fuzx_SOURCES = $(fuzx_files)
# fuzx_OBJECTS = $(fuzx_SOURCES:.cpp=.o)
# fuzx_MODULE = fuzx$(PYTHON_EXT_SUFFIX)

# # Custom compilation rule for source files
# # %.o: %.cpp
# # 	$(CXX) $(AM_CXXFLAGS) $(CXXFLAGS) $(PYBIND11_CPPFLAGS) $(PYTHON_INCLUDES) -fPIC -c $< -o $@

# # # Custom linking rule to create the Python extension module
# # $(fuzx_MODULE):	$(fuzx_OBJECTS)
# # 	$(CXX) \
# # 	$(fuse_OBJECTS) \
# # 	$(AM_LDFLAGS) $(LDFLAGS) \
# # 	$(fuse_LDADD) \
# # 	$(PYTHON_LIBS) \
# # 	 -shared $^ -o $@

# # $(fuse_OBJECTS) $(fuse_DEPENDENCIES) $(EXTRA_fuse_DEPENDENCIES)


# # Ensure the extension module is cleaned up on 'make clean'
# CLEANFILES += $(fuzx_OBJECTS)
# # CLEANFILES += $(fuzx_OBJECTS) $(fuzx_MODULE)

# # Target to build the extension module
# # all-local:	$(fuzx_MODULE)

endif

CLEANFILES += $(fuzx_files)

export_var_file = linking.cfg

fuzx_files = \
	$(export_var_file)
