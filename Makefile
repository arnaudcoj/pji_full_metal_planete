.PHONY: clean All

All:
	@echo "----------Building project:[ api - Debug ]----------"
	@cd "api" && "$(MAKE)" -f  "api.mk"
	@echo "----------Building project:[ tests - Debug ]----------"
	@cd "tests" && "$(MAKE)" -f  "tests.mk"
clean:
	@echo "----------Cleaning project:[ api - Debug ]----------"
	@cd "api" && "$(MAKE)" -f  "api.mk"  clean
	@echo "----------Cleaning project:[ tests - Debug ]----------"
	@cd "tests" && "$(MAKE)" -f  "tests.mk" clean
