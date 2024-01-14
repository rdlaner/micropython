include("$(PORT_DIR)/boards/manifest.py")

require("datetime")

# freeze_as_native("modules")
# freeze_as_native("packages")
freeze("modules")
freeze("packages")
