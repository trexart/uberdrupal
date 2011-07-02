api = 2
core = 6.x

; Includes ====================================================================

includes[] = https://raw.github.com/trexart/buildkit/6.x-1.x/core.make

includes[] = https://raw.github.com/trexart/buildkit/6.x-1.x/developer.make

includes[] = "https://raw.github.com/trexart/buildkit/6.x-1.x/standard.make"

includes[] = "https://raw.github.com/trexart/buildkit/6.x-1.x/images.make"

includes[] = "https://raw.github.com/trexart/buildkit/6.x-1.x/ubercart.make"

; Override buildkit ===========================================================

; Modules =====================================================================

projects[skinr][subdir] = contrib
projects[skinr][version] = 1.6

; Themes ======================================================================

projects[fusion][version] = 1.1
projects[acquia_prosper][version] = 1.1

; Libraries ===================================================================

; Profiles ====================================================================

projects[uberdrupal][type] = profile
projects[uberdrupal][download][type] = git
projects[uberdrupal][download][url] = git://github.com/trexart/uberdrupal.git
;projects[uberdrupal][download][branch] = 6.x-1.x
projects[uberdrupal][download][branch] = master