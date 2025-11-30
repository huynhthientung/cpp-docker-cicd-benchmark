DOCKERHUB_USER ?= tuilatung2001
APP_NAME       ?= cpp-docker-cicd-benchmark

DEV_VERSION    ?= 0.1.0
PROD_VERSION   ?= 0.1.0

IMAGE          ?= $(DOCKERHUB_USER)/$(APP_NAME):$(DEV_VERSION)

PROD_IMAGE     ?= $(DOCKERHUB_USER)/$(APP_NAME):$(PROD_VERSION)
PROD_LATEST    ?= $(DOCKERHUB_USER)/$(APP_NAME):latest

CHART_PATH     ?= helm/$(APP_NAME)

.PHONY: build push build-prod push-prod

## Build docker image (dev)
build:
	@echo "Building DEV IMAGE: $(IMAGE)"
	sudo docker build -t $(IMAGE) .
	sudo docker tag $(IMAGE) $(DOCKERHUB_USER)/$(APP_NAME):${DEV_VERSION}

## Push dev images
push:
	@echo "Pushing DEV images..."
	sudo docker push $(IMAGE)

## Build production image
build-prod:
	@echo "Building PROD IMAGE: $(PROD_IMAGE)"
	sudo docker build -t $(PROD_IMAGE) .
	sudo docker tag $(PROD_IMAGE) $(PROD_LATEST)

## Push production images
push-prod:
	@echo "Pushing PROD images..."
	sudo docker push $(PROD_IMAGE)
	sudo docker push $(PROD_LATEST)
