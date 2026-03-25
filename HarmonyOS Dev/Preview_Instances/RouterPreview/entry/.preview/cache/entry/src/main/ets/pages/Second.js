import router from '@ohos:router';
class Second extends ViewPU {
    constructor(parent, params, __localStorage, elmtId = -1) {
        super(parent, __localStorage, elmtId);
        this.content = "This is Page 2.";
        this.__text = new ObservedPropertySimplePU(router.getParams()["text"], this, "text");
        this.__data = new ObservedPropertyObjectPU(router.getParams()["data"], this, "data");
        this.__secondaryData = new ObservedPropertySimplePU('', this, "secondaryData");
        this.setInitiallyProvidedValue(params);
    }
    setInitiallyProvidedValue(params) {
        if (params.content !== undefined) {
            this.content = params.content;
        }
        if (params.text !== undefined) {
            this.text = params.text;
        }
        if (params.data !== undefined) {
            this.data = params.data;
        }
        if (params.secondaryData !== undefined) {
            this.secondaryData = params.secondaryData;
        }
    }
    updateStateVars(params) {
    }
    purgeVariableDependenciesOnElmtId(rmElmtId) {
        this.__text.purgeDependencyOnElmtId(rmElmtId);
        this.__data.purgeDependencyOnElmtId(rmElmtId);
        this.__secondaryData.purgeDependencyOnElmtId(rmElmtId);
    }
    aboutToBeDeleted() {
        this.__text.aboutToBeDeleted();
        this.__data.aboutToBeDeleted();
        this.__secondaryData.aboutToBeDeleted();
        SubscriberManager.Get().delete(this.id__());
        this.aboutToBeDeletedInternal();
    }
    get text() {
        return this.__text.get();
    }
    set text(newValue) {
        this.__text.set(newValue);
    }
    get data() {
        return this.__data.get();
    }
    set data(newValue) {
        this.__data.set(newValue);
    }
    get secondaryData() {
        return this.__secondaryData.get();
    }
    set secondaryData(newValue) {
        this.__secondaryData.set(newValue);
    }
    initialRender() {
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Flex.create({
                direction: FlexDirection.Column,
                alignItems: ItemAlign.Center,
                justifyContent: FlexAlign.Center
            });
            Flex.debugLine("pages/Second.ets(13:5)");
            Flex.width("100%");
            Flex.height("100%");
            if (!isInitialRender) {
                Flex.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Text.create(`${this.content}`);
            Text.debugLine("pages/Second.ets(17:7)");
            Text.fontSize(50);
            Text.fontWeight(FontWeight.Bold);
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Text.create(`${this.content}`);
            Text.debugLine("pages/Second.ets(20:7)");
            Text.fontSize(50);
            Text.onClick(() => {
                this.secondaryData = (this.data["array"][2]).toString();
            });
            Text.margin({ top: 20 });
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        this.observeComponentCreation((elmtId, isInitialRender) => {
            ViewStackProcessor.StartGetAccessRecordingFor(elmtId);
            Text.create(`Data that Page 1 send is: ${this.secondaryData}`);
            Text.debugLine("pages/Second.ets(26:7)");
            Text.fontSize(20);
            Text.margin({ top: 20 });
            Text.backgroundColor("red");
            if (!isInitialRender) {
                Text.pop();
            }
            ViewStackProcessor.StopGetAccessRecording();
        });
        Text.pop();
        Flex.pop();
    }
    rerender() {
        this.updateDirtyElements();
    }
}
ViewStackProcessor.StartGetAccessRecordingFor(ViewStackProcessor.AllocateNewElmetIdForNextComponent());
loadDocument(new Second(undefined, {}));
ViewStackProcessor.StopGetAccessRecording();
//# sourceMappingURL=Second.js.map