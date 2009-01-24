/* ASE - Allegro Sprite Editor
 * Copyright (C) 2001-2009  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef CORE_FILE_SYSTEM_H
#define CORE_FILE_SYSTEM_H

#include "jinete/jbase.h"
#include "jinete/jstring.h"

#include <vector>

struct BITMAP;
class FileItem;

typedef std::vector<FileItem*> FileItemList;

bool file_system_init();
void file_system_exit();

void file_system_refresh();

FileItem* get_root_fileitem();
FileItem* get_fileitem_from_path(const jstring& path);

bool fileitem_is_folder(FileItem* fileitem);
bool fileitem_is_browsable(FileItem* fileitem);

jstring fileitem_get_keyname(FileItem* fileitem);
jstring fileitem_get_filename(FileItem* fileitem);
jstring fileitem_get_displayname(FileItem* fileitem);

FileItem* fileitem_get_parent(FileItem* fileitem);
const FileItemList& fileitem_get_children(FileItem* fileitem);

bool fileitem_has_extension(FileItem* fileitem, const jstring& csv_extensions);

BITMAP *fileitem_get_thumbnail(FileItem* fileitem);
void fileitem_set_thumbnail(FileItem* fileitem, BITMAP *thumbnail);

#endif /* CORE_FILE_SYSTEM_H */

