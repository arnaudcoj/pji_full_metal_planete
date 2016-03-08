.PHONY: clean All

All:
	@echo "----------Building project:[ api - Debug ]----------"
	@cd "api" && "$(MAKE)" -f  "api.mk"
	@echo "----------Building project:[ interface - Debug ]----------"
	@cd "interface" && "$(MAKE)" -f  "interface.mk"
	@echo "----------Building project:[ game - Debug ]----------"
	@cd "game" && "$(MAKE)" -f  "game.mk"
clean:
	@echo "----------Cleaning project:[ api - Debug ]----------"
	@cd "api" && "$(MAKE)" -f  "api.mk"  clean
	@echo "----------Cleaning project:[ interface - Debug ]----------"
	@cd "interface" && "$(MAKE)" -f  "interface.mk"  clean
	@echo "----------Cleaning project:[ game - Debug ]----------"
	@cd "game" && "$(MAKE)" -f  "game.mk" clean
