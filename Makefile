.PHONY: clean All

All:
	@echo "----------Building project:[ api - Debug ]----------"
	@cd "api" && "$(MAKE)" -f  "api.mk"
clean:
	@echo "----------Cleaning project:[ api - Debug ]----------"
	@cd "api" && "$(MAKE)" -f  "api.mk" clean
